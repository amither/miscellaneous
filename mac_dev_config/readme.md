## install brew
## install vim
系统自带的vim有各种问题
```
brew install vim
brew install macvim
```
/usr/local/bin/vim加到PATH
```
brew install autojump
```
## disable csrutil
`csrutil status` view sip status
1. Turn off your Mac (Apple > Shut Down).
2. Hold down Command-R and press the Power button. Keep holding Command-R until the Apple logo appears.
3. Wait for OS X to boot into the OS X Utilities window.
3. Choose Utilities > Terminal.
4. Enter csrutil disable.
5. Enter reboot.

## install gnu coreutils
```
brew install coreutils
```
for commands as gdircolors, gls

## install iterm2
## config solarized color
```
wget https://ethanschoonover.com/solarized/files/solarized.zip
```
config iterm2, vim color according to readme in solarized dir.

## config dircolor
```
git clone --recursive https://github.com/joel-porquet/zsh-dircolors-solarized
cp zsh-dircolors-solarized/dircolors-solarized/dircolors.256dark ~/.dircolors.256dark
```
eval `gdircolors ~/.dircolors.256dark` will be executed in zshrc.

## cp zshrc ~/.zshrc

## mac vim8 config
vim 8 has a very strong package mangement.
reference [My Vim IDE setup for Go](https://app.getpocket.com/read/2568835637)

```
git clone https://github.com/fatih/vim-go.git ~/.vim/pack/dist/start/vim-go
git clone https://github.com/scrooloose/nerdtree.git ~/.vim/pack/dist/start/nerdtree
git clone https://github.com/vim-airline/vim-airline ~/.vim/pack/dist/start/vim-airline
git clone https://github.com/tpope/vim-fugitive.git ~/.vim/pack/dist/start/vim-fugitive
git clone https://github.com/ctrlpvim/ctrlp.vim.git ~/.vim/pack/dist/start/ctrlp

git clone https://github.com/morhetz/gruvbox.git ~/.vim/pack/colors/start/gruvbox
```

### todo
auto-pairs


