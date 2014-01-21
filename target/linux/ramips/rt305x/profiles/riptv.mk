#
# Copyright (C) 2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/RIPTV_FXS_001
	NAME:=RIPTV FXS 001
	PACKAGES:=kmod-usb-core kmod-usb-ohci kmod-usb2 kmod-ledtrig-usbdev \
	kmod-i2c-core kmod-i2c-gpio
endef

define Profile/RIPTV_FXS_001/Description
	Package set for RIPTV FXS 001
endef

$(eval $(call Profile,RIPTV_FXS_001))
