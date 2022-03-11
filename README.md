# RenderObjectQueueing
A neat way to queue render objects (Rectangles, Filled rectangles, Lines, Text and Circles). You will have to replace the "render::" functions with whatever you use.

"vec2d" holds two ints (x,y)

"color" holds an RGBA value

example:

```cpp
framework::add_rectangle_object(vec2d(2,4),vec2d(2,2),color(255,255,255,255);
..
// call somewhere after you're done setting up all the render objects
framework::handle_rendering_abstracts();
```
