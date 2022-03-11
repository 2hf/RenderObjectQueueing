#include "post_queue_rendering.hpp"
#include "helpers/render.hpp"

void framework::add_text_object( vec2d pos, std::string tag, color color_, LPD3DXFONT font )
{
	text_objects.push_back( { pos,tag,color_,font } );
}

void framework::add_rounded_rectangle_object( vec2d pos, vec2d size, color color_, float radius, float smoothing )
{
	quad_or_two_vertice_objects.push_back( { drawable_object_type::ROUNDED_RECTANGLE,pos,size,color_,radius,smoothing } );
}

void framework::add_rectangle_object( vec2d pos, vec2d size, color color_ )
{
	quad_or_two_vertice_objects.push_back( { drawable_object_type::RECTANGLE,pos,size,color_ } );
}

void framework::add_outlined_rectangle_object( vec2d pos, vec2d size, color color_ )
{
	quad_or_two_vertice_objects.push_back( { drawable_object_type::OUTLINED_RECTANGLE,pos,size,color_ } );
}

void framework::add_line_object( vec2d pos, vec2d size, color color_ )
{
	quad_or_two_vertice_objects.push_back( { drawable_object_type::LINE,pos,size,color_ } );
}

void framework::handle_rendering_abstracts( )
{
	for ( const auto& object : quad_or_two_vertice_objects ) {
		switch ( object.drawable_object_type_ ) {
			case drawable_object_type::RECTANGLE: {
				render::rectangle( object.pos, object.size, object.color_ );
				break;
			}
			case drawable_object_type::ROUNDED_RECTANGLE: {
				render::rectangle_round( object.pos, object.size, object.radius, object.smoothing, object.color_, { 0, 0, 0, 0 } );
				break;
			}
			case drawable_object_type::OUTLINED_RECTANGLE: {
				render::rectangle( object.pos - vec2d(1,1), object.size + vec2d(2,2), object.color_ );
				render::rectangle( object.pos, object.size, object.color_ );
				break;
			}
			case drawable_object_type::LINE: {
				render::line( object.pos, object.size, object.color_ );
				break;
			}
		}
	}
	quad_or_two_vertice_objects.clear( );
	for ( const auto& object : text_objects ) {
		render::text( object.pos, object.tag, object.font, object.color_, 0 );
	}
	text_objects.clear( );
}
