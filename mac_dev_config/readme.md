## install brew
## install vim
系统自带的vim有各种问题
安装vim8
```
brew install vim
brew install macvim
```
如果vim8不支持python(执行:echo has('python3')看结果是否为1), 首先安装python3-devel，然后源码编译vim
```
#默认安装到/usr/local
./configure --enable-pythoninterp --enable-python3interp
make && make install
```

/usr/local/bin/vim加到PATH
```
brew install autojump
```

## git config
```
#if behind a proxy
git config --global --add http.proxy http://devnet-proxy.oa.com:8080
git config --global url."https://".insteadOf git://
git config --global url."https://github.com/".insteadOf git@github.com
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

## install universal ctags
```
brew install --HEAD universal-ctags/universal-ctags/universal-ctags
```
```
git clone https://github.com/universal-ctags/ctags.git
```

## mac vim8 plugin
vim 8 has a very strong package mangement.  reference [My Vim IDE setup for Go](https://app.getpocket.com/read/2568835637)
放到.vim/pack/*/start, 会自动加载
放到.vim/pack/*/opt, 可手动加载
```
git clone https://github.com/morhetz/gruvbox.git ~/.vim/pack/colors/start/gruvbox

git clone https://github.com/fatih/vim-go.git ~/.vim/pack/dist/start/vim-go
git clone https://github.com/scrooloose/nerdtree.git ~/.vim/pack/dist/start/nerdtree
git clone https://github.com/vim-airline/vim-airline ~/.vim/pack/dist/start/vim-airline
git clone https://github.com/tpope/vim-fugitive.git ~/.vim/pack/dist/start/vim-fugitive
git clone https://github.com/ctrlpvim/ctrlp.vim.git ~/.vim/pack/dist/start/ctrlp
git clone https://github.com/ludovicchabant/vim-gutentags.git  ~/.vim/pack/dist/start/vim-gutentags
git clone https://github.com/jiangmiao/auto-pairs.git ~/.vim/pack/plugins/start/auto-pairs
# Install YouCompleteMe, Compiling YCM with semantic support for C-family languages through clangd
git clone https://github.com/ycm-core/YouCompleteMe.git ~/.vim/pack/dist/start/YouCompleteMe && cd  ~/.vim/pack/dist/start/YouCompleteMe && git submodule update --init --recursive && python3 ./install.py --clang-completer
```


