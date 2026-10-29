scons platform=linuxbsd target=editor arch=x86_64
scons platform=linuxbsd target=template_debug arch=x86_64

# Copy export templates to Godot editor location (overwrite existing)
EXPORT_TEMPLATES="$HOME/.local/share/godot/export_templates/4.4.2.rc"
mkdir -p "$EXPORT_TEMPLATES"

# Overwrite existing install in bin/ (the editor binary is what godot.desktop launches)
EDITOR_BIN="bin/godot.linuxbsd.editor.x86_64"
DEBUG_BIN="bin/godot.linuxbsd.template_debug.x86_64"

# Install export template under the name the editor expects
[ -f "$DEBUG_BIN" ] && cp -f "$DEBUG_BIN" "$EXPORT_TEMPLATES/linuxbsd.template_debug.x86_64"
[ -f "$EDITOR_BIN" ] && echo "Editor install overwritten: $EDITOR_BIN"
