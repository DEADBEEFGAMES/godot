scons platform=ios target=template_debug generate_bundle=yes

# Copy export templates to Godot editor location (overwrite existing)
EXPORT_TEMPLATES="$HOME/Library/Application Support/Godot/export_templates/4.4.2.rc"
mkdir -p "$EXPORT_TEMPLATES"
if [ -f bin/godot_ios.zip ]; then
	mv -f bin/godot_ios.zip bin/ios.zip
fi
[ -f bin/ios.zip ] && cp -f bin/ios.zip "$EXPORT_TEMPLATES/"
done