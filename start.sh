# Compile the OpenGLab
# Exec.: 
# $ sh start.sh

FILES="./main.cpp"
OUT="main" 

if g++ --std=c++17 '$FILES' -o '$OUT' -lglut -lGL | echo "Compiling..."; then

  echo "Compiled Successful"
  
  if ./'$OUT' | echo "Running..."; then
    echo "Closed"
  else
    echo "Error: On running -> ./main"
  fi

else
  echo "Error: On compiling -> ./main.cpp"
fi