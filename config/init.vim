call plug#begin('~/.local/share/nvim/plugged')
Plug 'mileszs/ack.vim'
Plug 'kien/ctrlp.vim'
Plug 'jiangmiao/auto-pairs'
Plug 'vim-scripts/taglist.vim'
Plug 'flazz/vim-colorschemes'
call plug#end()

let mapleader=","
set background=dark
colorscheme solarized
set number
set autoindent
set tabstop=4
set shiftwidth=4
set expandtab
syntax on
set background=dark
imap jj <Esc>:w<cr>
set foldmethod=indent
set foldlevel=99
set foldcolumn=0
set clipboard=unnamed
nnoremap <space> za
nnoremap x "_x
nnoremap X "_X
nnoremap d "_d
nnoremap dd "_dd
nnoremap D "_D
vnoremap d "_d
vnoremap dd "_dd

nnoremap <leader>x ""x
nnoremap <leader>X ""X
nnoremap <leader>d ""d
nnoremap <leader>dd ""dd
nnoremap <leader>D ""D
vnoremap <leader>d ""d
vnoremap <leader>dd ""dd
