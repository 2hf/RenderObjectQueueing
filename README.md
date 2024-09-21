# RenderObjectQueueing
A neat way to queue render objects (Rectangles, Filled rectangles, Lines, Text and Circles). You will have to replace the "render::" functions with whatever you use. Found myself struggling to do 2d rendering with menus and such, this made work a lot easier and as an industry bare mininmum standard should be used for every 2d rendering space.

"vec2d" holds two ints (x,y) for positional information in the two dimensional space (this could easily be made 3d if for some reason anyone would ever want to do so..)

"color" holds an RGBA value (Red, Green, Blue, Alph/Transparency)

example:

```cpp
framework::add_rectangle_object(vec2d(2,4),vec2d(2,2),color(255,255,255,255);
..
// call somewhere after you're done setting up all the render objects
framework::handle_rendering_abstracts();
```
