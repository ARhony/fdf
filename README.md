# fdf
In this project I discovered the basics of graphic programming, and in particular how to place points in space, how to join them with segments and more importantly how to observe the scene from a specific viewpoint. This project introduced me to “events” programming. FDF is about creating a simplified graphic “wireframe” (“Fils De Fer” in french) representation of a relief landscape linking various points (x, y, z) via segments. The coordinates of this landscape was stored in a file passed as a parameter to my program.

![screenshot](https://user-images.githubusercontent.com/24727426/30224351-b7bd5d40-94ce-11e7-8c0f-b6b6194d2fe0.png)

# MLX
I used my first graphic library: minilibX. This library was developed internally and include the minimum neccessary to open a window, light a pixel and deal with events to this window: KEYOARD, MOUSE and EXPOSE. This is an introduction to "events" programming.

# How
Git clone the project, make it and choose a file with the extension .fdf in the folder "files" as an argument.

```
git clone https://github.com/ARhony/fdf.git fdfRhony
cd fdfRhony
make
./fdf files/basic.fdf
```
# Controls


# Next?
The colors based on the z axis + better perspective
