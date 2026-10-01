#!/bin/sh
disk="/dev/nvme0n1"
localtime="/usr/share/zoneinfo/Canada/Pacific"
lang="en_US.UTF-8"
hostname="arch"
root_password="root"
user_name="wheels"

umount "${disk}"
parted --script --align optimal "${disk}" \
    mklabel gpt \
    mkpart esp fat32 0% 1GiB \
    set 1 esp on \
    mkpart root ext4 1024MiB 100%
mkfs.fat -F 32 "${disk}p1"
mkfs.ext4 "${disk}p2"
mount "${disk}p2" /mnt
mount --mkdir "${disk}p1" /mnt/boot

pacman -Sy archlinux-keyring
pacstrap -K /mnt base linux linux-firmware grub efibootmgr networkmanager sudo

genfstab -U /mnt >> /mnt/etc/fstab

arch-chroot /mnt

ln -sf ${localtime} /etc/localtime
hwclock --systohc

locale-gen
echo "LANG=${lang}" >> /etc/locale.conf

echo "${hostname}" >> /etc/hostname

printf "${root_password}\n${root_password}\n" | passwd

grub-install --target=x86_64-efi --efi-directory=/boot --bootloader-id=GRUB
grub-mkconfig -o /boot/grub/grub.cfg

systemctl enable NetworkManager.service

sed --in-place "/%wheel ALL=(ALL:ALL) ALL/s/^# //g" /etc/sudoers

useradd --create-home --groups wheel "${user_name}"
passwd -d wheels
