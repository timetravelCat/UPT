# 🚀 UPT - Ultimate Project Template

An Ultimate Project Template for **C/C++**, **CMake**, **Python**, **CUDA**, **ROS2**, and more app development.

---

## 📋 Template Overview

This template is designed with a primary focus on enabling individuals to set up a development environment for robotics applications on their local machines. It adopts the most modern and universal approaches for application development.

---

## 🛠 Prerequisites

- [**VSCode**](https://code.visualstudio.com/): This template heavily relies on numerous VSCode extensions to maximize the potential of the VSCode editor. Many extensions will be installed inside the Docker image. However, at least these extensions are mandatory on the HOST machine to ensure a seamless development experience:
  - [Docker](https://marketplace.visualstudio.com/items?itemName=ms-azuretools.vscode-docker): This extension makes it easy to build, manage, and deploy containerized applications from within VSCode.
  - [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers): This extension lets you use a Docker container as a full-featured development environment, enabling consistent development setups across different machines.
  - [Devcontainer CLI](https://containers.dev/supporting#devcontainer-cli): The Devcontainer CLI allows you to manage your development containers from the command line.

- [**Docker**](https://www.docker.com/): Docker is a mandatory requirement for this template. It allows you to package applications and their dependencies into a container, ensuring consistency across different environments. Developers must customize the provided Dockerfile to suit their specific development environment. Key components include:
  - [Docker Desktop](https://www.docker.com/products/docker-desktop/): Docker Desktop is an easy-to-install application for your Mac or Windows environment that enables you to build and share containerized applications and microservices. It includes Docker Engine, Docker CLI client, Docker Compose, Docker Content Trust, Kubernetes, and Credential Helper.

- [**WSL**](https://learn.microsoft.com/en-us/windows/wsl/install): If your host machine is Windows, you need to install the Windows Subsystem for Linux (WSL). WSL allows you to run a Linux distribution alongside your Windows installation, providing a native Linux experience for development. This is particularly useful for running Linux-based tools and scripts seamlessly on a Windows machine.

- [**VcXsrv**](https://vcxsrv.com/): If your host machine is Windows, you need to install VcXsrv. VcXsrv is an open-source X server for Windows that allows you to run graphical applications from your Docker container on your Windows desktop. This is particularly useful for running GUI applications inside your development container.

- [**NVIDIA Container Toolkit**(optional)](https://docs.nvidia.com/datacenter/cloud-native/container-toolkit/latest/install-guide.html): If you want CUDA support, you need to install the NVIDIA Container Toolkit. This toolkit allows you to build and run GPU-accelerated Docker containers.

---

## 💡 Philosophy of This Template

- Strive for maximum productivity in robotics application development.
- Prioritize automation and simplicity in setup processes (without compromising robustness).
- Default to using the latest operating systems and build tools while ensuring that their versions can be easily configured and adjusted.

---

## ✨ Key Features of This Template

- **Editor-based linting**
  - [C/C++ Advanced Lint](https://marketplace.visualstudio.com/items?itemName=jbenden.c-cpp-flylint): In the container, Clang, CppCheck, FlawFinder, PC-lint Plus, Flexelint, and lizard are installed and configured in project settings.

- **Editor-based formatting**
  - [Clang-Format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format): In the container, clang-format will be installed.
  - [Ruff](https://marketplace.visualstudio.com/items?itemName=charliermarsh.ruff): Supports Python formats.
  - [CMake Language Support](https://marketplace.visualstudio.com/items?itemName=josetr.cmake-language-support-vscode): Supports CMake formats.

- **Editor-based Git/CMake/Test/Python interactions, snippets**
  - Check all [VSCode extensions](.devcontainer/devcontainer.json).

- **CMake template for C/C++ projects**
  - Test by [Catch2](https://github.com/catchorg/Catch2)

- **Pre-Commit hooks**

- **workflow by github actions**
  - Check all [workflows](.github/workflows/)

---

## 📂 Project Structure
    📦UPT
    ┣ 📂.devcontainer
    ┃ ┣ 📜Dockerfile
    ┃ ┗ 📜devcontainer.json
    ┣ 📂.github
    ┃ ┗ 📂workflows
    ┃ ┃ ┣ 📜clang-format.yml
    ┃ ┃ ┣ 📜clang-tidy.yml
    ┃ ┃ ┣ 📜cppcheck.yml
    ┃ ┃ ┣ 📜flawfinder.yml
    ┃ ┃ ┣ 📜multi-platform.yml
    ┃ ┃ ┣ 📜python-lint.yml
    ┃ ┃ ┗ 📜stale.yml
    ┣ 📂.vscode
    ┃ ┣ 📜launch.json
    ┃ ┗ 📜settings.json
    ┣ 📂cmake
    ┃ ┣ 📜ExampleProjectConfig.cmake.in
    ┃ ┣ 📜Version.h.in
    ┃ ┣ 📜clang-tidy.cmake
    ┃ ┣ 📜cuda.cmake
    ┃ ┗ 📜cppcheck.cmake
    ┣ 📦docs
    ┃ ┣ 📜index.md
    ┣ 📂include
    ┃ ┗ 📂ExampleProject
    ┃ ┃ ┗ 📜Version.h
    ┣ 📂src
    ┃ ┣ 📜example_debug.cpp
    ┃ ┣ 📜example_project.cpp
    ┃ ┗ 📜example_cuda.cu
    ┣ 📂test
    ┃ ┣ 📜CMakeLists.txt
    ┃ ┗ 📜test_example.cpp
    ┣ 📜.clang-format
    ┣ 📜.gitignore
    ┣ 📜.pre-commit-config.yaml
    ┣ 📜CMakeLists.txt
    ┣ 📜LICENSE
    ┣ 📜README.md
    ┗ 📜mkdocs.yml
---

## 🚀 Getting Started
1. Ctrl + Shift + P : >Dev Containers: Open Folder in Container..
  - This takes a lot of time if Anaconda or CUDA feature enabled in [***devcontainer.json***](.devcontainer/devcontainer.json)

2. CMake Project Setup
  - Rename project name in [***CMakeLists.txt***](CMakeLists.txt).
  - Rename folder name of [***include/ExampleProject***](include)
  - Rename [***cmake/ExampleProjectConfig.cmake.in***](cmake)

3. CUDA (Optional)
  - Uncomment cuda features in [***devcontainer.json***](.devcontainer/devcontainer.json)

4. Documentations via mkdocs (Optional)
  - Check **GitHub Pages** and Select **Deploy from a branch**, Branch as **gh-pages**, **/(root)**.
  - Check [***docs workflow***](.github/workflows/docs.yml), [***mkdocs configuration***](mkdocs.yml)

5. Adjust VSCode workspace settings (Optional)
  - "c-cpp-flylint.defines"
  - "c-cpp-flylint.standard"

---

## 📜 License
This project is licensed under the Apache License 2.0 - see the LICENSE file for details.

---

## 🙏 Acknowledgements
Thanks to all the contributors who have made this project possible.
Special thanks to the open-source community for their invaluable resources and support.

---

## 📞 Contact
For any inquiries or support, please contact timetravelCat@gmail.com

---

## ✅ TODO
- [x] Automatically detect CUDA and CUDA hardware.
- [ ] ROS2 branch, for ROS2-based packages.
- [x] Project documentation template (using mkdocs).
- [ ] Option for direct use of Docker image including all major features.
- [x] Add CI/CD pipeline for automated testing and deployment.
