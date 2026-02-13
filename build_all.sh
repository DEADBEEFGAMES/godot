scons platform=macos target=template_debug arch=arm64
scons platform=macos target=template_release arch=arm64
scons platform=macos target=template_debug arch=x86_64
scons platform=macos target=template_release arch=x86_64 generate_bundle=yes
scons platform=macos arch=arm64 generate_bundle=yes

# Copy export templates to Godot editor location (overwrite existing)
EXPORT_TEMPLATES="$HOME/Library/Application Support/Godot/export_templates/4.4.2.rc"
mkdir -p "$EXPORT_TEMPLATES"
if [ -f bin/godot_macos.zip ]; then
	mv -f bin/godot_macos.zip bin/macos.zip
fi
[ -f bin/macos.zip ] && cp -f bin/macos.zip "$EXPORT_TEMPLATES/"
for f in bin/godot.macos.template*; do
	[ -e "$f" ] && cp -f "$f" "$EXPORT_TEMPLATES/"
done
