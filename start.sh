# Compile the OpenGL Studies Code
# Exec. on terminal: 
# $ sh start.sh


# FILES: Set files that you want to compile
FILES="./main.cpp"
# OUT: Set the compiled program name
OUT="main" 

# Operations
COMPILE="g++ --std=c++17 $FILES -o $OUT -lglut -lGL"
RUN="./$OUT"

# Depuration
if $COMPILE; then
  
  echo "Compiled Successful"

  if $RUN; then
    echo "Closed"
  else
    echo "Error: On running -> ./main"
  fi

else
  echo "Error: On compiling -> ./main.cpp"
fi