/**************************************************************************/
/*  test_shader_language.h                                                */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_SHADER_LANGUAGE_H
#define TEST_SHADER_LANGUAGE_H

#include "servers/rendering/shader_language.h"
#include "servers/rendering/shader_types.h"

#include "tests/test_macros.h"

namespace TestShaderLanguage {

static ShaderLanguage::ShaderCompileInfo _make_spatial_compile_info() {
	ShaderLanguage::ShaderCompileInfo info;
	info.functions = ShaderTypes::get_singleton()->get_functions(RS::SHADER_SPATIAL);
	info.render_modes = ShaderTypes::get_singleton()->get_modes(RS::SHADER_SPATIAL);
	info.shader_types = ShaderTypes::get_singleton()->get_types();
	return info;
}

TEST_CASE("[ShaderLanguage] Spatial VELOCITY output compiles") {
	ShaderLanguage sl;
	const String code(
			"shader_type spatial;\n"
			"void fragment() {\n"
			"	VELOCITY = vec2(0.25, -0.5);\n"
			"}\n");

	ShaderLanguage::ShaderCompileInfo info = _make_spatial_compile_info();
	Error err = sl.compile(code, info);
	CHECK_MESSAGE(err == OK, sl.get_error_text());
}

TEST_CASE("[ShaderLanguage] Spatial VELOCITY remains optional") {
	ShaderLanguage sl;
	const String code(
			"shader_type spatial;\n"
			"void fragment() {\n"
			"	ALBEDO = vec3(1.0);\n"
			"}\n");

	ShaderLanguage::ShaderCompileInfo info = _make_spatial_compile_info();
	Error err = sl.compile(code, info);
	CHECK_MESSAGE(err == OK, sl.get_error_text());
}

TEST_CASE("[ShaderLanguage] Spatial VELOCITY enforces vec2 type") {
	ShaderLanguage sl;
	const String code(
			"shader_type spatial;\n"
			"void fragment() {\n"
			"	VELOCITY = vec3(1.0);\n"
			"}\n");

	ShaderLanguage::ShaderCompileInfo info = _make_spatial_compile_info();
	CHECK(sl.compile(code, info) != OK);
}

} // namespace TestShaderLanguage

#endif // TEST_SHADER_LANGUAGE_H
