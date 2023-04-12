#!/bin/bash
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
DYLD_FRAMEWORK_PATH=/Users/chenruiyao/Qt/6.4.2/macos/lib${DYLD_FRAMEWORK_PATH:+:$DYLD_FRAMEWORK_PATH}
export DYLD_FRAMEWORK_PATH
QT_PLUGIN_PATH=/Users/chenruiyao/Qt/6.4.2/macos/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
