#pragma once
#include "helpers/color.hpp"
#include <array>
#include <vector>
#include <utility>
#include <string>
#include "includes.hpp"
#include "helpers/vec2d.hpp"

namespace framework {
	class abstract_base_object {
	public:
		vec2d pos;
	};
	class text_object : public abstract_base_object {
	public:
		std::string tag;
		color color_;
		LPD3DXFONT font;
		text_object( vec2d pos,std::string tag,color color_,LPD3DXFONT font ) {
			this->pos.x = pos.x;
			this->pos.y = pos.y;
			this->tag = tag;
			this->color_ = color_;
			this->font = font;
		}
	};
	enum class drawable_object_type {
		RECTANGLE, ROUNDED_RECTANGLE, OUTLINED_RECTANGLE, LINE, MAX_OBJECT_TYPE
	};
	// no need to make separate objects anymore, this can essentially serve every other thing we will ever need.
	// idk what to call it
	class quad_or_two_vertice_object : public abstract_base_object {
	public:
		drawable_object_type drawable_object_type_;
		vec2d size;
		color color_;
		float radius;
		float smoothing;

		quad_or_two_vertice_object( drawable_object_type drawable_object_type_, vec2d pos, vec2d size, color color_ ) {
			this->pos = pos;
			this->drawable_object_type_ = drawable_object_type_;
			this->size = size;
			this->color_ = color_;
		}
		quad_or_two_vertice_object( drawable_object_type drawable_object_type_, vec2d pos, vec2d size, color color_, float radius, float smoothing ) {
			this->pos = pos;
			this->drawable_object_type_ = drawable_object_type_;
			this->size = size;
			this->color_ = color_;
			this->radius = radius;
			this->smoothing = smoothing;
		}
	};
	inline std::vector<text_object> text_objects;
	inline std::vector<quad_or_two_vertice_object> quad_or_two_vertice_objects;

	void add_text_object( vec2d pos, std::string tag, color color_, LPD3DXFONT font );
	void add_rounded_rectangle_object( vec2d pos, vec2d size, color color_, float radius, float smoothing );
	void add_rectangle_object( vec2d pos, vec2d size, color color_ );
	void add_outlined_rectangle_object( vec2d pos, vec2d size, color color_ );
	void add_line_object( vec2d pos, vec2d size, color color_ );

	void handle_rendering_abstracts( );
}