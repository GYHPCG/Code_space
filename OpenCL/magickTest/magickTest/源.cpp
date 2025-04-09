#include<Magick++.h>


int main()
{
	     
	
	     Magick::Image image("50x50","blue");
	     image.pixelColor(49, 49, "red");
	     image.write("red_pixel.png");
	
		
		  system("pause");
		 return 0;
}