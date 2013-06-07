vorbis-music   
============

###About   
C++(C)でvorbisを再生するサンプルプロジェクトです。   
コードは基本的にC++で記述されていますがデコードしているコードの部分はCでも同様ですので流用可能です。  

###Compile it  
CMakeを使ってコンパイルします。  
OSに適切なコンパイラなどが入っていることを確認してください。gccまたはclangを推奨します。またその場合GNU Makeも必要です。  
  
  
1.CMakeをインストールしていなかったらインストールしてください。  
CMakeは以下のページで配布されています。  
 http://www.cmake.org/  

2.依存関係の解決  
このソフトはQt5及びlibvorbisに依存します。この2つをインストールしてください。  
libvorbisはwindows(MinGW)向けにコンパイルしたものを用意していますのでそちらを利用しても大丈夫です。  

Qt5 -> http://qt-project.org/  

libvorbis -> http://xiph.org/vorbis/  

libvorbis for windows -> https://dl.dropboxusercontent.com/u/23369413/oss/vorbis-libraries.zip  

3.CMakeを実行する  
以下ではUNIXターミナル(MinGWでも可能)を例に説明します。(CMakeにはGUIツールが付属するのでそちらを利用しても大丈夫です)   

まず、vorbis-musicのディレクトリに移動します。

    $ cd vorbis-music

cmakeを実行します。デフォルトでReleaseでビルドされます。debugにしたい場合はオプションで指定できます。  
また、libvorbisなどの位置を指定する場合はLIBVORBIS_PREFIXなどにオプションで設定してください。(-Dオプションを使います)  

    $ cmake .

成功しない場合は依存関係などのチェックをしてください。QtなどはqmakeコマンドにPATHが通っていないと認識しません。  

4.ビルドする  
GNU Makeでビルドします。

    $ Make

成功すれば、vorbis-musicのバイナリが生成されます。install処理は記述していないのでmake installは動きません。  


### License  
Copyright (c) 2013, masahiro NAGATA  
All rights reserved.  
  
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:  
  
    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.  
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  
  
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
