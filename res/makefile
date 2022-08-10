
LittleMartians: main.o mlGraphics.o mlEntity.o mlAssets.o mlEnemy.o mlPlayer.o mlInput.o  mlShot.o mlType.o mlUtilities.o mlTime.o
	mkdir -p build
	clang++ -o build/LittleMartians.app main.o  mlGraphics.o mlEntity.o mlAssets.o mlEnemy.o mlPlayer.o mlInput.o  mlShot.o mlType.o mlUtilities.o mlTime.o -lSDL2 -lSDL2_ttf -lSDL2_image -Wc++11-extensions

main.o:
	clang++ -c main.cpp

mlGraphics.o: mlGraphics.h
	clang++ -c mlGraphics.cpp

mlEntity.o: mlEntity.h
	clang++ -c mlEntity.cpp

mlAssets.o: mlAssets.h
	clang++ -c mlAssets.cpp

mlEnemy.o: mlEnemy.h
	clang++ -c mlEnemy.cpp

mlPlayer.o: mlPlayer.h
	clang++ -c mlPlayer.cpp

mlInput.o: mlInput.h
	clang++ -c mlInput.cpp

mlShot.o: mlShot.h
	clang++ -c mlShot.cpp

mlType.o: mlType.h
	clang++ -c mlType.cpp

mlUtilities.o: mlUtilities.h
	clang++ -c mlUtilities.cpp

mlTime.o: mlTime.h
	clang++ -c mlTime.cpp

clean:
	rm *.o
	rm build/LittleMartians.app
