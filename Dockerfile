# Use a lightweight base image
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the C++ source code into the container
COPY . .

# Compile the C++ code
RUN g++ -o singlyll singlyll.cpp

# Specify the command to run your application
CMD ["./singlyll"]
