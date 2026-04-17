#!/bin/bash
# Export project variables
export PRJ=diagram-client
export SRC=src
export SRC_C=$SRC/main/c
export BUILD=target
export BUILD_DEBUG=$BUILD/exe/debug
# Variable name LIB reserved for ./configure
export REQUIRED_LIBS="gtk+-3.0 webkit2gtk-4.1"

# Array of prerequisite packages
REQUIRED_PACKAGES="build-essential libwebkit2gtk-4.1-dev"

# Array of avoided packages
AVOIDED_PACKAGES=""

apt_install() {
  RESULT=$(apt list --installed 2>&1 | grep "$2")
  if [ -z "$RESULT" ]; then 
    if [ -z "$1" ]; then
      sudo apt update
    fi
    sudo apt install -y -qq "$2"
    echo "1"
  else 
    echo "$1"
  fi 
}

apt_uninstall() {
  if apt list --installed 2>&1 | grep -q "$1"; then 
    sudo apt purge --autoremove -y -qq "$1"
  fi 
}

install() {
  UPD=0
  echo "$REQUIRED_PACKAGES" | tr ' ' '\n' | while read -r package; do
    if [ ! -z "$package" ]; then
      UPD=$(apt_install $UPD "$package")
    fi
  done

  echo "$AVOIDED_PACKAGES" | tr ' ' '\n' | while read -r package; do
    if [ ! -z "$package" ]; then
      apt_uninstall "$package"
    fi
  done
}

install
