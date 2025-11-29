## v0.0.1 - Project structure created
- Added top level directories for assets, docs, include, and src.

## v0.1.1 - added all src and header files, created subdirectories
- Added subdirectories to src and include, the contents will mirror each other
- Added all source and header files. included all headers in respective source files,
- Added the include hierarchy to all header files(RIP MY SANITY)
- Added foward declartions for player to respective headers.
- updated CMakeLists.txt to include all source files(RIP MY SANITY YET AGAIN)

## v0.1.2 Window and loop
- Basic defintions added to GameApp and game, game has render, update and init, none are actually properly defined, they're just they as proof of concepts for now
- GameApp has two objects declared as private class level variables Game(To call game methods), and RenderWindow. It also has one method run, which is used to launch the game loop.
- The loop now runs window shows up can close it, all that good stuff.
