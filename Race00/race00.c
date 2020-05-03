void mx_printstr(const char *s);

void mx_printchar(char c);

int mx_strlen(const char *s);

static void bottom_topBorder(int width){
  int border;

  for (border = 0; border < width; border++){
    if (width == 1) {
      mx_printstr("<=>");
    } else if ( border == 0) {
      mx_printstr("<=");
    } else if (border == width - 1) {
      mx_printstr("=>");
    } else {
      mx_printstr("-");
    }
  }
  mx_printstr("\n");
}

static void left_rightBorder(int line){
  if(line % 2 == 0){
    mx_printchar('*');
  } else {
    mx_printchar('+');
  }
}

void race00(int map_length, int map_width, int one_y, int one_x){
  int h, w;

  if (map_width + map_length <= 1 || map_width < one_x || map_length < one_y) {
    mx_printstr("");
  } else {
      bottom_topBorder(map_width);
      for (h = 0; h < map_length; h++){
	left_rightBorder(h);
	for(w = 0; w < map_width; w++){
	  if(h == one_y && w == one_x){
	    mx_printstr("1");
	  } else {
	    mx_printstr("0");
	  } 
	}
	left_rightBorder(h);
	mx_printchar('\n');
      }
      bottom_topBorder(map_width);
  }
}
