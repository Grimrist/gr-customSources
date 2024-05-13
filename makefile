make full_install: 
	rm -rf build
	mkdir build
	cd build; cmake ..; make; sudo make install; sudo ldconfig

make uninstall:
	cd build; sudo make uninstall
