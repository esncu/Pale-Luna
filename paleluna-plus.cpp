#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <chrono>
#include <cctype>
#include <cstdlib> // Required for std::system

#ifndef _WIN32
  #include <sys/ioctl.h>
  struct winsize w;
#endif

void clear(){
#ifdef _WIN32
  std::system("cls"); 
#else
  std::system("clear");
#endif
}

uint8_t d; //ABCD EFGH A=Extra?, B=Rope, C=K.Paulsen, D,Shovel, FGH=screenProgress
std::string in;

#define wait(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

void c(){
  while(true)
    c();
}

//kitty
#ifdef _WIN32 
  #include <conio.h>
#else
  #include <termios.h>
  #include <unistd.h>
#endif

const std::string& b64_Treasure = "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";

const std::string& b64_Nevins = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAhDEnFx6kAAAImSURBVFjDvVehUsNAEN3LZEJjIuKpZFAILLY1FZj+QU1tpwZRHYFhamOwqBpEDfwAhgEUuviKmjAxQWQ22dvuXS4t6Zomucu+zdvdd1sVTqEI+wFwyzY58OfbRQ4uFieB+L6EoeIkKGybXEFtwdgC8LsC5n5MgfhSVKeysB+Al21yDbQpb4cax0HzJMCugpD8el0Cuph3ynxLqfBd+hUAYD0ba/ej5arVOg0EA9B0INvkcPFxBQAAP7ffWhty565Gg6BtiB9t1QHJHh5fquv5ZOi8ZkpH2A9qBs6fL7VNn29f/1oDzkJkyv1ouYKiqFVbKeW8dlQXUGopgMsz6V3nACTKlFIVEC1MvKbrrgeSipOgwLa4eYoAAOD97lc7TI7pAgkc8cJ+UNYA7U1bGmh1c3ptaxyU/vou+v+625UXJBCp1RC42m8QoL0U4M31fU9LgW0mGESRHGTLocQ/dBixAbYZSpyVkPd5+z0FbBfIyJl+GAEAZCkARL29FkMhoQ4pUJMW1IKkM4JsqHAKRZbKB06TirmayXeckLNAyjuO11laf7WJfs6OUkp731SY1i6QCslEP0+DqfL5/OHrk3BPnIzpFzQxQAMOp80zoVUJERh73rX1qv1puR8DkaYv42GUpaWj9WxcqR4XHxv4fDKE9WwMgyjSGOQfqtUAXcQATCLE6W2zf68G2qodB8dnSHkbMzLQ5XhOT0ZP2kApOvZPC/rjfvD+DwxlOnR5ur2eAAAAAElFTkSuQmCC";

const std::string& b64_Grass = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAiEpjnqQkAAAEESURBVFjDxZcxEsMgDATlKzzjNg/I9/ySfDSfyEwaUjkFY6Q7KTGUWAtIHJK8bLu17b5aP17Pt53N9zZmZhUeI6MIjuxYHtEJDy8zg+ERQZ4no9ArPFhg5E2VP9XAMdd/82yzPBTBqEIsiXAUWlaYLA9vsSjk0WEYHqpnowWz/HJ7rI3NXFHIMzyyz4cVYsTjnwpneNjkASZkShRUHmr+PrOv8HQm9Dap8IjyN7tJlv/mAbXjYfVAaSBbz9Wrog5wdWVctt1aBHpplgmzx8/vB5g361W8Ki/VgoynEY+r2m/3Ffy6y1F4zCjBdCa8vBx74WPuOcMj87PpbaTyyCpb7RlG/AfBRii0V2E2uQAAAABJRU5ErkJggg==";

const std::string& b64_Edge = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAiCGWFUHMAAAGLSURBVFjDtVc7TgNBDDVWtNLWlJG2TIVQTsIBuADX2NNwnihKgVKCUlIjISSoZjUx/jx7YZqssvNm/Hl+9t6MT/Q9TgPJ9fH6Sdr/cg8R0TgNyzMR0e5wT+f9EcKztSkCy33tdz5tFyOQxZGFvWdINLJ4jkBeJPp3lUiO00CbPo9aPrV8e57PdxciuvxKgYVXOSDz6nmj7W2XI3jOEM4LpYzEeX9cR0KLCxaxZBVIoyw8eyz1Qi4Pk+dYOiLxHHmG6oBcJR1AysojaauCx807LF4cXYhGporn6sGWTsynLT1/3dLbwwuEZ/qjFQlUWYrRKGSr6cqAjP5r+/vnRkKvCno8Zzy0jFyDZ6S0kEuq77litTVB9VWA4lfNA56H5TKsdsYlAoASXhnglV3fJ6I0aTqA4P9tHoCbEVLzXsfUpuJGQgSf6gWesVaYIzyvmQWyug9xIDImmnKy5cprWrC2Whk2HYC7YSTFsAGChKl27IU/mxptSNXwsBJGPIl0wMJz9cPU+urppRjB/wC+uVI9ZkJlNgAAAABJRU5ErkJggg==";

const std::string& b64_Tree = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAhO/F4YqYAAAHRSURBVFjDtVc7TsQwEJ1YxlIKUoQWBYE4yl6CE+QKoK1ziByIO1DQkIZqt6CxlGYp0EReZ35OxEirlZxM5s34zfO4qnu41F2A3OI0A7We2vk4AwBAO2zzj9MMjnvJErwdArRDWICU+KM5DWGcZjY4GgeC8xcB5E7WTBBEiX/dBXBWB3wvzz63h8fnomqSHMC1/FkcQQzeDgE+Xj9ZfyqWs5ZZC74wvweSD5x56WMITit7voUR5iv/9D9fdxJLLcHxPfzhVsSRrmy6dqUDFEkswbWu0Kxqh3ChlEtyLgGlJeE5hqLT+fhHrD0mybIv+ZClW0o6QAVg4UAeMK0Wtq5EdC+1n6kqPV+pCDPcujuA7iQD4Hp277a0Q4Cvt+9VFdN4rBKW7uXWQ8pJ+r9VA7hK3d888TpgyZ6bfCzbwRF6BUDq+zjKldHAUCC8BeVCmn4bIaU2XA0k3HyXHzglKigd5xU1Fe85hKiMpVmCJCFVCQugNDDyJfWlRM5bTzzqDkBlKgGuu7Use4v84qilCdShaeD95adI0n2OLHfMER+aZhMfOJl3Ujtpl4o9xFwB4IbH/zZXepWSDPe/pArOeilJg2iBNJVME/Wle2bNVpNnXP8F5WBJWozyQIYAAAAASUVORK5CYII=";

const std::string& b64_Spark = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAhLQWs1/cAAAFJSURBVFjDxZYxDsIwDEVdCxWVEXauB2dghzNwvu5dQbCUqRBMHH87Fc3Sqs2L7eTbcdMdaOz2Lclx75+U+y7nEBHV8KxNsmBrHsqz5eEUZWQgPFtQKRJt6z08o4AWTS2f1cD0Tf4rzY3y7BGMV4hVItS2FhUmynNpMWvLh9ODavivOhBNudt1rOJZ886bfhG+27cfB7zpgzpl8RxdeDg9su/eDGFaeDTbczuiN5yMdndZ/0S/OTau2rDKGZWpVhq7y5ru/fOdDdNz+mdd42Yl1BZJv6dGtd3SCtPPEVjVTRqTx6A5nDYpabNSdKCkB3k0OcOWnqr7Ac8dADuAGkwjTt+9DnOuUslssCphDb98P4C0ztqNWVI8wrvTEO33PTz/q/2GNWAthnQ5Hp7nFpWXd2tg7sHoWSLnHOE50u+VDHl5jiobqR8I/wKWwkJM9/VzxgAAAABJRU5ErkJggg==";

const std::string& b64_Ledge = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAvKZxCPmAAAAFzSURBVFjDvVe9TsQwDP5qVafr0gGJFXXtAtItDKy8BE9wj8ATMNyT8CSsrKyItRsLiOWYcnJCHNtpDi9tUn/x5x/VTjfscRyuNkjl6+MHuf1UBwDW4ElS0sCanhVPGsPgZY1Y8KSBSp5IoffgyQqQvFmLz9ZA2Eu/lXRr8eQpGG8hripCKbTWwrTiqXSYFnKNjAVPXs+kA2vx3cXT5ogGYvnzZQncj+OJwOvjN/5TdodtXIS7w/b0DO+tDXIbANDd3F5HKbh8ewePSI5Iul9aS2cAwDJPcQokWeYpS7CF9BalklFOzor5QyA9RAIHPf5d09XImFJwTumXeWqeVy0afJ2NACeVC7ulFqxOmVNQa0AlMOwREbh7HpuEukTy5eEzJsAbiiRriOWMB5tqMwpNRiJnIcY9Tluyuxvyrudtv8ERTqDXLhjWWaB2NKNzTDkePLUeMr34ZhNRk6m4FD7LzFeDp5rLZsmQF0+1F0vL1duC/wVOMyASvqGFagAAAABJRU5ErkJggg==";

const std::string& b64_Steps = "iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAALGPC/xhBQAAAAFzUkdCAdnJLH8AAAAgY0hSTQAAeiYAAICEAAD6AAAAgOgAAHUwAADqYAAAOpgAABdwnLpRPAAAAAlwSFlzAAAuIwAALiMBeKU/dgAAAAd0SU1FB+kMERAzBD/qP0gAAAGgSURBVFjDvVcxbsMwDKQJI3AWDwWyFl69tEaWDl3zCb+gT+gLOuQlfYnXDl4CeAqyesuSwksyyaBlUSJlt9xs8aQjdaKoZPsB9+3zBmy7XQZw/bd9AACW4JFzCoFDflI8hhiaKGNMgscQyBcJl3oNHqUALpqleKcGzD97zOcbi0eNYLRCXCRCLrVSYUrx6JsslPIQGQketZFxE8bik6evzR1WMEnlcxI45PlI4OfzF/7T9sdsSsCQ2B8zAABo6uuqJ8PMS9dIXt9eJgR2p/OETGwpfv/OZ4vZ1pfFPAOco4sgZ019HQmoNBBjlByXSZ+lrkk4sNHE9Cy3zmilWUs5B3oibpdhXGS+WLYsA31ZOJ2pcJp6CO65XZQoWTsb9NupAUrKOIcisrexq1qREMUi7MsCuqqdRSpVO7sFdrHhJtydztBV03F7a7RiBgBIaFfsKzpLI+X0EryMzCXDkZMQs7NMj7H6NqS3nrZMm0AogTT0wJD2ArGtGf5Fl6PB49pNpha/Wke0SlfsS5+k54vBY8xj07eQFo+xD0vJ01uCfwB9iUELuDP94QAAAABJRU5ErkJggg==";

void img(){
#ifdef __linux__  //kitty
  std::cout<<"\n";
  for(int i = 0; i < w.ws_col/4; ++i)
    std::cout<<" ";
  std::cout
    << "\033_G"
    << "a=T,f=100,c=" << w.ws_col/2 << ",r=" << w.ws_row/2 <<";"
    << b64_Treasure
    << "\033\\"
    "\n";
#else             //iterm2
  std::cout<<"\n";
  std::cout
        << "\x1b]1337;File="
        << "name=inline;"
        << "inline=1;"
        << "width=" << 32 << ";"
        << "height=" << 32 << ":"
        << b64_Treasure
        << "\x07";
    std::cout.flush();
#endif
}

void sprite(std::string b64){
#ifdef __linux__  //kitty
  std::cout
    << "\033_G"
    << "a=T,f=100,c=2,r=1;"
    << b64
    << "\033\\";
#else             //iterm2
  std::cout
        << "\x1b]1337;File="
        << "name=inline;"
        << "inline=1;"
        << "width=" << 2 << ";"
        << "height=" << 1 << ":"
        << b64
        << "\x07";
    std::cout.flush();
#endif
}

char getChar() {
#ifdef _WIN32
    return _getch();
#else
    termios oldt, newt;
    char c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    read(STDIN_FILENO, &c, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
#endif
}

struct MapData{
  char elements[8][16];
};

struct MapData Maps[6] = {
  {
    //--0-DATA--------
    //    e          t
    //    e          t
    //    e          t
    //    e          t
    // +  e          t
    //   e           t
    //  e            t
    // e             t
    {
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', '+', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'}
    }
  },{
    //--1-DATA--------
    //t              t
    //t     tt       t
    //t      t       t
    //t              t
    //t              t
    //t
    //t      tt
    //t      tt
    {
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    }
  },{
    //--2-DATA--------
    //t
    //t
    //t
    //t
    //t
    //          tttttt
    //
    //
    {
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', 't', 't', 't', 't'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    }
  },{
    //--3-DATA--------
    //
    //
    //     |||||||||||
    //    e
    //    et
    //    e          t
    //    e          t
    //    e          t
    {
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', 'e', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', 'e', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'}
    }
  },{
    //--4-DATA--------
    //
    //               t
    //|||||||t|||||||t
    //       t       t
    //       tt      t
    //t              t
    //t      t       t
    //t   t          t
    {
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'|', '|', '|', '|', '|', '|', '|', 't', '|', '|', '|', '|', '|', '|', '|', 't'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'},
      {'t', ' ', ' ', ' ', 't', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 't'}
    }
  },{
    //--5-DATA--------
    //
    //t
    //t|||||cccc||||||
    //t
    //t
    //t
    //t
    //t
    {
      {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', '|', '|', '|', '|', '|', 'c', 'c', 'c', 'c', '|', '|', '|', '|', '|', '|'},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {'t', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    }
  }
};

int player_y=7, player_x=10;

void render(){
  clear();
  for(int row = 0; row < 8; ++row){
    for(int col = 0; col < 16; ++col){
      if(row==player_y && col==player_x)
        sprite(b64_Nevins);
      else{
        switch(Maps[d & 0x07].elements[row][col]){
          case ' ':
            sprite(b64_Grass); //grass
            break;
          case 't':
            sprite(b64_Tree); //tree
            break;
          case 'e':
            sprite(b64_Edge); //edge
            break;
          case '|':
            sprite(b64_Ledge); //slope
            break;
          case 'c':
            sprite(b64_Steps); //slope with steps
            break;
          case '+':
            if(d & 0x08)
              sprite(b64_Spark); //grass with sparkle
            else
              sprite(b64_Grass);
            break;
          default:
            std::cout<<"E"; //error
            break;
        }
      }
    }
    std::cout<<"\n";
  }
  std::cout<<"\nWASD to move.";
}
bool checkPos(int x, int y){
  char c = Maps[d & 0x07].elements[player_y + y][player_x + x];
  return c == ' ' || c == 'c' || c == '+';
}
void movePlayer(char move){
  switch(move){
    case 'w':
    case 'W':
      if(player_y > 0){
        if(checkPos(0, -1))
          --player_y;
      }else if((d & 0x07) < 3){
        d+=3;
        player_y+=7;
      }
      break;
    case 's':
    case 'S':
      if(player_y < 7){
        if(checkPos(0, 1))
          ++player_y;
      }else if((d & 0x07) >= 3){
        d-=3;
        player_y-=7;
      }
      break;
    case 'a':
    case 'A':
      if(player_x > 0){
        if(checkPos(-1, 0))
          --player_x;
      }else if((d & 0x07) % 3 != 0){
        if((d & 0x07) == 4)
          d|=0x08;
        d-=1;
        player_x+=15;
      }
      break;
    case 'd':
    case 'D':
      if(player_x < 15){
        if(checkPos(1, 0))
          ++player_x;
      }else if((d & 0x07) % 3 != 2){
        if((d & 0x07) == 3)
          d&=0xF7;
        d+=1;
        player_x-=15;
      }
      break;
  }
}
void extra();
//kitty

void anim(std::string s, int ms){
  for(int i=0; i < s.size(); ++i){
    std::cout<<s[i]<<std::flush;
    if(!std::isspace(static_cast<unsigned char>(s[i])))
      wait(ms);
  }
}

std::string center(std::string s){
  #ifndef _WIN32
    ioctl(0, TIOCGWINSZ, &w);
    if(s.size() > w.ws_col)
      return s;
    for(int i = 0; i <= (w.ws_col - s.size())/2; ++i)
      s = ' ' + s;
  #endif
  return s;
}

int main() {
  #ifndef _WIN32
    ioctl(0, TIOCGWINSZ, &w);
  #endif

  //title
  clear();
  #ifndef _WIN32
    std::cout
      <<"     █████▄  ▄▄▄  ▄▄    ▄▄▄▄▄   ██     ▄▄ ▄▄ ▄▄  ▄▄  ▄▄▄ \n"
      <<"     ██▄▄█▀ ██▀██ ██    ██▄▄    ██     ██ ██ ███▄██ ██▀██\n"
      <<"     ██     ██▀██ ██▄▄▄ ██▄▄▄   ██████ ▀███▀ ██ ▀██ ██▀██\n"
      <<"\nCaps Lock is recommended for this game.\nPress enter to start...";
  #else
    anim("P A L E  L U N A", 50);
    std::cout<<"\nCaps Lock is recommended for this game.\nPress enter to start...";
  #endif
  
  std::cin.get();

  //s1
  clear();
  anim(center("You are in a dark room. Moonlight shines through the window.\n"), 50);
  anim(center("There is GOLD in the corner, along with a SHOVEL and a ROPE.\n"), 100);
  anim(center("There is a DOOR to the EAST.\n"), 25);
  std::cout<<"Command?\n";
  while(1) {
    in="";
    std::cout<<"> ";
    std::getline(std::cin, in);
    std::cin.clear();
    if(in == "OPEN DOOR")
      d |= 0x01;
    else if(in == "GO EAST")
      if (d & 0x01)
        break;
      else
        anim("...\n", 1000);
    else if(in == "PICK UP ROPE")
      d |= 0x40;
    else if(in == "PICK UP GOLD")
      if(d & 0x40){
        d |= 0x20;
      }else{
        std::cout<<"Glistening gold, too high to reach.\n";
      }
    else if(in == "PICK UP SHOVEL")
      d |= 0x10;
    else
      std::cout<<"Invalid Command.\n";
  }
  
  //s2
  d &= 0xF8;
  clear();
  while(1){
    anim(center("Reap your reward.\n"), 50);
    if(d & 0x20)
      anim(center("PALE LUNA SMILES AT YOU.\n"), 200);
    anim("You are in a forest. There are paths to the NORTH,", 50);
    if ((d & 0x07) != 0) 
      anim(" SOUTH,", 50);
    anim(" WEST, and EAST.\n", 50);
    std::cout<<"Command?\n";
    in="";
    std::cout<<"> ";
    std::getline(std::cin, in);
    std::cin.clear();
    if(in == "GO NORTH")
      if((d & 0x07) == 0 || (d & 0x07) == 4){
        d+=1;
        clear();
      }else
        c();
    else if(in == "GO EAST")
      if((d & 0x07) == 1 || (d & 0x07) == 3){
        d+=1;
        clear();
      }else
        c();
    else if(in == "GO SOUTH")
      if((d & 0x07) == 2){
        d+=1;
        clear();
      }else if((d & 0x07) == 7)
        break;
      else
        c();
    else if(in == "GO WEST")
      if((d & 0x07) == 5 || (d & 0x07) == 6){
        d+=1;
        clear();
      }else
        c();
    else if(in == "USE GOLD" && (d & 0x20)){
      clear();
      anim("Not here.\n", 50);
    }else if(in == "USE SHOVEL" && (d & 0x10)){
      clear();
      anim("Not now.\n", 50);
    }else if(in == "USE ROPE" && (d & 0x40)){
      clear();
      anim("You've already used this.\n", 200);
    }else{
      clear();
      std::cout<<"Invalid Command.\n";
    }
  }

  //s3
  d &= 0xF8;
  clear();
  while(1){
    anim(center("PALE LUNA SMILES WIDE.\n"), 200);
    anim(center("There are no paths.\n"), 50);
    anim(center("PALE LUNA SMILES WIDE.\n"), 200);
    anim(center("The ground is soft.\n"), 50);
    anim(center("PALE LUNA SMILES WIDE.\n"), 200);
    anim(center("Here.\n"), 250);
    std::cout<<"Command?\n";
    in="";
    std::cout<<"> ";
    std::getline(std::cin, in);
    std::cin.clear();
    if(in == "DIG HOLE" && (d & 0x07) == 0)
      if(d & 0x10){
        d+=1;
        clear();
      }else{
        clear();
        std::cout<<"You can't.\n";
      }
    else if(in == "DROP GOLD" && (d & 0x07) == 1)
      if(d & 0x20){
        d+=1;
        clear();
      }else{
        clear();
        std::cout<<"Where is she?\n";
      }
    else if(in == "FILL HOLE" && (d & 0x07) == 2)
      break;
    else
      c();
  }
  
  clear();
  anim(center("Congratulations.\n"), 66);
  anim(center("--  40.24248 --\n"), 100);
  anim(center("-- -121.4434 --\n"), 100);

  //kitty only
  wait(3000);
  anim("\n\n\nCoordinates", 100);
  anim("....?", 500);
  wait(2000);
  anim("\n\nOh! maybe there's buried gold there!", 50);
  wait(4000);
  anim("\n\nIt's about 20 miles away...", 100);
  wait(2000);
  anim(center("\n\n\nI'm sure mom won't notice if I come home a bit late..."), 200);
  wait(5000);
  extra();
  clear();
  img();
  std::cout<<"\n\n";
  wait(1000);
  anim(center("--BREAKING NEWS--"), 50);
  wait(1000);
  anim(center("\n11-year-old Karen Paulsen, reportedly missing since"), 50);
  anim(center("\nthe sixteenth of March last year, has been found."), 50);
  wait(1000);
  anim(center("\n\nWarning, the following images may be disturbing"), 50);
  anim(center("\nto some."), 50);
  wait(1000);
  anim(center("\n\nPaulsen's skull has been identified in the woods"), 100);
  anim(center("\nnear Elam Campground in Northen California this morning."), 100);
  wait(1000);
  anim(center("\n\n15-year-old Michael Nevins thought he was on a"), 50);
  anim(center("\ntreasure hunt, but the gold he found uncovered"), 50);
  anim(center("\na new piece of evidence that changes everything."), 50);
  wait(1000);
  anim(center("\n\nNevins said he was following the coordinates"), 50);
  anim(center("\nin an infamous videogame renowned for it's mystery"), 50);
  anim(center("\nand shoddy programming, "), 50);
  anim(center("\nP A L E  L U N A"), 100);
  wait(1000);
  anim(center("\n\nWhat's more disturbing is that the game was"), 50);
  anim(center("\nsupposedly created and spread many years before"), 50);
  anim(center("\nPaulsen's dissapearance. Authorities are now"), 50);
  anim(center("\ntrying to reverse-engineer this game to look"), 50);
  anim(center("\nfor any more clues left inside, encouraging"), 50); //hello!
  anim(center("\nanyone with a copy or more information to"), 50);
  anim(center("\nreport it immediately."), 50);
  wait(2000);

  return 0;
}

void extra(){
  d=0;  //ABCD EFGH
        //FGH = screen 3 4 5
        //             0 1 2
        //E   = flag to check if coming to 0 via 3,
        //      turns off with 4. used for gold sparkle
        //A   = flag to end game
  clear();
  do{
    render();
    movePlayer(getChar());
    if(Maps[d & 0x07].elements[player_y][player_x] == '+')
      break;
  }while(1);
}
