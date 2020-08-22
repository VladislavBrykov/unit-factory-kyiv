#include "./inc/header.h"

static void li(int m, int n, char arr[][n], int startX, int startY, int endX,
        int endY) {
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int mark = 0;
  int stop = 0;
  int arrInt[m][n];
  if (arr[startX][startY] == '#') {
    mx_printerr("entry point cannot be an obstacle\n");
  } else if (arr[endX][endY] == '#') {
    mx_printerr("exit point cannot be an obstacle\n");
  } else if (arr[startY] > arr[n] || arr[startX] > arr[m] ||
	     arr[endY] > arr[n] || arr[endX] > arr[m]) {
    mx_printerr("points are out of map range\n");
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (arr[i][j] == '#') {
	  arrInt[i][j] = -1;
	} else if (arr[i][j] == '.') {
	  arrInt[i][j] = -2;
	}
      }
    }
    arrInt[startX][startY] = mark;
    while (!stop) {
      stop = 1;
      for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
	  if (arrInt[i][j] == mark) {
	    for (int k = 0; k < 4; ++k) {
	      int ix = i + dx[k], iy = j + dy[k];
	      if (ix >= 0 && ix < m && iy >= 0 && iy < n &&
		  arrInt[ix][iy] == -2) {
		arrInt[ix][iy] = mark + 1;
		stop = 0;
	      }
	    }
	  }
	}
      }
      mark++;
    }
    int x = endX;
    int y = endY;
    int dist = mark - 1;
    int exit = arrInt[endX][endY];
    if (exit < 0) {
      mx_printerr("route not found\n");
    } else {
      mx_printstr("dist=");
      mx_printint(dist);
      mx_printchar('\n');
      mx_printstr("exit=");
      mx_printint(exit);
      mx_printchar('\n');
      while (exit > 0) {
	exit--;
	for (int k = 0; k < 4; ++k) {
	  int ix = x + dx[k], iy = y + dy[k];
	  if (ix >= 0 && ix < m && iy >= 0 && iy < n &&
	      arrInt[ix][iy] == exit) {
	    arrInt[ix][iy] = 0;
	    x = x + dx[k];
	    y = y + dy[k];
	    break;
	  }
	}
      }
      for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
	  if (arrInt[i][j] == -1) {
	    arr[i][j] = '#';
	  } else if (arrInt[i][j] == dist &&
                               arrInt[i][j] == arrInt[endX][endY] &&
		     i == endX && j == endY) {
	    arr[i][j] = 'X';
	  } else if (arrInt[i][j] == dist && arrInt[i][j] != 0) {
	    arr[i][j] = 'D';
	  } else if (arrInt[i][j] == -2 || arrInt[i][j] > 0) {
	    arr[i][j] = '.';
	  } else if (arrInt[i][j] == 0) {
	    arr[i][j] = '*';
	  }
	}
      }
    }
  }
}

static bool mx_valid_char(char c) {
  if (c == ',' || c == '#' || c == '.' || c == '\n') {
    return true;
  } else {
    return false;
  }
}

static void mx_valid_params(char *argv[]){
  for (int i = 2; i < 6; i++) {
    int j = 0;
    while (argv[i][j] != '\0') {
      if (!mx_isdigit(argv[i][j])) {
        mx_printerr("usage: ./race04 [file_name] [x1] [y1] [x2] [y2]\n");
        exit(-1);
      }
      j++;
    }
  }
}

static void rect(char *argv[]){
  char buff;
  int commas = 0;
  int newline = 0;
  int temp_commas = 0;
  int file = open(argv[1], O_RDONLY);
  if(file == -1) {
    mx_printerr("map does not exist\n");
    exit(1);
  }
  while(read(file, &buff, 1)) {
      if(buff != '\n') {
	if(buff == ',') {
	  commas++;
	}
      }
      else {
	newline++;
	if (newline == 1) {
	  temp_commas = commas;
	}
	else {
	  if(commas != temp_commas) {
	    mx_printerr("map error\n");
	    exit(1);
	  }
	}
	commas = 0;
      }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 6) {
    mx_printerr("usage: ./race04 [file_name] [x1] [y1] [x2] [y2]\n");
    exit(-1);
  }

  mx_valid_params(argv);
  
  if ((mx_strcmp(argv[2],argv[4])) == 0 && (mx_strcmp(argv[3],argv[5])) == 0) {
    mx_printerr("error\n");
    exit(-1);
  }  
  
  rect(argv);
  
  int fd = open(argv[1], O_RDONLY);
  char ch;

  while (read(fd, &ch, 1)) {
    if (!mx_valid_char(ch)) {
      mx_printerr("map error\n");
      exit(-1);
    }
  }
  close(fd);

  int startX = mx_atoi(argv[3]);
  int startY = mx_atoi(argv[2]);
  int endX = mx_atoi(argv[5]);
  int endY = mx_atoi(argv[4]);
  int count = 0;
  int x = 0;
  int y = 0;
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    mx_printerr("map does not exist\n");
    exit(-1);
  }
  while (read(fd, &ch, 1)) {
    if (ch == '\n') {
      x++;
    }
    if (ch != ',') {
      count++;
    }
  }
  close(fd);
  fd = open(argv[1], O_RDONLY);
  y = (count - x) / x;
  char arr[x][y];
  int tempX = 0, tempY = 0;

  while (read(fd, &ch, 1)) {
    if (ch != ',') {
      arr[tempX][tempY] = ch;
      if (ch == '\n') {
	tempX++;
	tempY = 0;
      } else {
	tempY++;
      }
    }
  }
  li(x, y, arr, startX, startY, endX, endY);
  int targetFile = open("path.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
  
  if (targetFile == -1) {
    mx_printerr("error\n");
  }
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      write(targetFile, &arr[i][j], 1);
    }
    write(targetFile, "\n", 1);
  }
  close(fd);
  close(targetFile);
  exit(0);
}
