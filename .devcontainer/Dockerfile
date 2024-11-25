# Copyright 2024 timetravelCat
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# * ROS2 image
FROM osrf/ros:humble-desktop-full
# [foxy|humble|jazzy]-desktop-full

# * ubuntu image
# FROM mcr.microsoft.com/devcontainers/base:noble
# [noble|jammy|focal]

# * Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# * Set the default terminal shell to bash
SHELL ["/bin/bash", "-c"]

# * Update and upgrade system packages
RUN apt-get update -y && apt-get upgrade -y

# * Install system dependencies
# WARN catch2 is not available in the ubuntu focal
RUN apt-get install -y --no-install-recommends \
    build-essential \
    bash-completion \
    cmake \
    python3-pip \
    python3-venv \
    python-is-python3 \
    clang \
    clang-format \
    clang-tidy \
    cppcheck \
    catch2 \
    flawfinder

# * Enable bash completion
RUN sudo rm /etc/apt/apt.conf.d/docker-clean

# * Install lizard system-wide
RUN sudo pip install lizard pre-commit
# RUN sudo pip install --break-system-packages lizard pre-commit # WARN if ubuntu noble, --break-system-packages is required

# * Configure user
ARG USERNAME=ubuntu
ARG USER_UID=1000
ARG USER_GID=1000

RUN if id -u $USERNAME >/dev/null 2>&1; then \
    userdel -r $USERNAME; \
    fi \
    && if getent passwd $USER_UID >/dev/null 2>&1; then \
    existing_user=$(getent passwd $USER_UID | cut -d: -f1); \
    userdel -r $existing_user; \
    fi \
    && groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

# * Post-installation Actions for CUDA
RUN echo "export PATH=\${PATH}:/usr/local/cuda/bin" >> ~/.bashrc
RUN echo "export LD_LIBRARY_PATH=\${LD_LIBRARY_PATH}:/usr/local/cuda/lib64" >> ~/.bashrc

# * Setup python virtual environment
# RUN python3 -m venv venv \
#     && . venv/bin/activate \
#     && pip install --no-cache-dir --upgrade pip

# Set the entrypoint to bash
ENTRYPOINT ["/bin/bash"]
