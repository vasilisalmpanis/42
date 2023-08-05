#!/bin/bash

# Check if git is installed
if ! command -v git &> /dev/null; then
    git --version
else
    echo "Git already installed"
fi
if [ -d "$HOME/homebrew" ]; then
    echo "The 'homebrew' folder exists in the home directory."
else
    mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew
    echo "export PATH=$HOME/homebrew/bin:$PATH" >> ~/.zshrc
fi
# Check if zsh is installed
if ! command -v zsh &> /dev/null; then
    brew install zsh
else
    echo "Zsh already installed"
fi
# Check if Oh My Zsh is already installed
if [ -d "$HOME/.oh-my-zsh" ]; then
    echo "Oh My Zsh is already installed."
else
    # Install Oh My Zsh
    sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

    # Set zsh as the default shell
    chsh -s $(which zsh)
    echo "ZSH_DISABLE_COMPFIX='true'" >> ~/.zshrc
    git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
    echo "plugins=(zsh-autosuggestions)" >> ~/.zshrc
    echo "Oh My Zsh has been installed. Please restart your terminal to start using it."
fi


