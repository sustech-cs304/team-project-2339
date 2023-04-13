#!/bin/bash
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/chenruiyao/Qt/6.4.2/macos/libexec/moc "$@"
