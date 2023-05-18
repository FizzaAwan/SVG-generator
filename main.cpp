//Afham Bashir. 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void svg_start(ostream& f, int width, int height);                     //function declaration for beginging of the svg file 
void svg_end(ostream& f);                                             // funiction declaration for he last line of svg file 
void ellipse (ostream& f, int cx, int cy, int rx, int ry, string fill_color, int stroke_width, string stroke_color); 
// funiction declaration for writing line in xml in svg file for ellipses.

int main () {
  int cx= 1000;     // the cx is intialized at cordinate of center is at 1000
  int cy= 1000;    // the cy variable is y cordinate of the center and initialized at 1000. 
  int rx= 900;      //the radius in respect of x, initialized at 900. 
  int ry= 900;      //the radius in respect of y, initialized at 900. rx=ry means intialized as a circle. 


	ofstream fout("Graphic.svg");          //starts outfile stream to an svg file named Graphic. 
  svg_start(fout, 2000, 2000);                  // calls svg start function with 2000 width and 2000 height. 
  ellipse(fout, 1000, 1000, 900, 900, "blue", 1, "blue");       //calls ellipse function with a circle that is blue, is the backgroun of entire image, radius of 900. 
  ellipse(fout, 1000, 1000, 15, 15, "white", 1, "white");       //calls ellips function with a circle that is white, with radius 15, at center of entire svg image. 
  

  for( int i= 0; i<50; i++){           // count controlled loop with with 50 iterations, 50 ellipses. 
    rx -= 2*i;                        // every iteration of the loop the X radius shrinks twice as fast the number of past iterations. 
    ry -= 1*i;                         // y radius shrinks by the number of past iterations.
    ellipse(fout, cx, cy, rx, ry, "transparent", 5, "lawngreen");   //calls ellips function that loops to make green skrinking ellipses. 
  }

  rx= 900; ry= 900;         // the x and y radius become 900 again, so the second overlapping tangent ellipses allign with the first set of ellipse.  

  for( int j= 0; j<50; j++){        // count controlled loop, now using j as counter, because i was used in the last. 
    rx -= 1*j;                      // x radius shrinks by the number of past iterations
    ry -= 2*j;                      // every iteration of the loop the Y radius shrinks twice as fast the number of past iterations.
    ellipse(fout, cx, cy, rx, ry, "transparent", 5, "red"); // calls ellipse function that loops to make red skrinking ellipses that are tangent to the first set of green ellipses. 
  }

  svg_end(fout);            // calls end of svg function to complete the svg file. 
	return 0;                 // end of main function. 
}

void svg_start(ostream& f, int width, int height) {               // function for start of the svf file, with file name stream, and height and width of svg image. 
  f << "<svg width=\"" << width << "\" height=\"" << height << "\"";        // xml code for svg file start. 
  f << " xmlns=\"http://www.w3.org/2000/svg\">\n";                          
}

void svg_end(ostream& f) {                          // function for writing the ending xml code of the svg file. 
  f << "</svg>\n";
}

void ellipse (ostream& f, int cx, int cy, int rx, int ry, string fill_color, int stroke_width, string stroke_color) { //// funiction for writing line in xml in svg file for ellipse shape using a center x & y, and specific x radis and y radis and a fill and border color and width. 

  f << "<ellipse cx=\""<<cx <<"\" cy=\""<<cy<<"\" rx=\""<<rx<<"\" ry=\""<<ry<<"\" fill=\""<<fill_color<<"\" "; 
  f << "stroke=\""<<stroke_color<< "\" stroke-width=\""<< stroke_width<<"\" />\n";     // writes ellipse center in xy coordinates, followed by x radius and y radous, and the fill colors, the border width, and lastly the boreder color. 
} 