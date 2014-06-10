#
# Copyright (C) 2012 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/MT7620_FXS_001
	NAME:=MT7620 FXS 001
	PACKAGES:=kmod-usb-core kmod-usb-ohci kmod-usb2 kmod-ledtrig-usbdev \
	kmod-i2c-core kmod-i2c-gpio
endef

define Profile/MT7620_FXS_001/Description
	Package set for MT7620 FXS 001
endef

$(eval $(call Profile,MT7620_FXS_001))
