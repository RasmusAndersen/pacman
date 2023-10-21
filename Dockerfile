# Use the official Ubuntu 18.04 as the base image
FROM ubuntu:18.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Update the package repository and install necessary packages
RUN apt-get update -y && apt-get install -y \
    git \
    cmake \
    build-essential \
    libgl1-mesa-dev \
    python3-tk \
    qtdeclarative5-dev && \
    rm -rf /var/lib/apt/lists/*

# Clone the GitHub repository
RUN git clone https://github.com/RasmusAndersen/pacman.git /opt/pacman

# Create a build directory
WORKDIR /opt/pacman/build

# Run CMake and make
RUN cmake ..
RUN make

# Clean up to reduce image size (optional)
RUN apt-get remove -y git cmake build-essential && \
    apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set the entry point (optional)
CMD ["./behavior_tree_editor"]