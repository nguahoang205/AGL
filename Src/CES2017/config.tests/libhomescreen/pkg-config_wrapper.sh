#!/bin/sh
PKG_CONFIG_SYSROOT_DIR=/opt/poky-agl/3.0.0+snapshot/sysroots/cortexa15hf-neon-agl-linux-gnueabi
export PKG_CONFIG_SYSROOT_DIR
PKG_CONFIG_LIBDIR=/opt/poky-agl/3.0.0+snapshot/sysroots/cortexa15hf-neon-agl-linux-gnueabi/usr/lib/pkgconfig
export PKG_CONFIG_LIBDIR
exec pkg-config "$@"
