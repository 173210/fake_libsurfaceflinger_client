Fake libsurfaceflinger_client for NMI MTV Libraries
===============

#概要
NMIの以下のライブラリをAndroid 4.4(KitKat)で動作させるためのライブラリです。

・libCdAbLayer.so	md5sum: 3d208fd745da1b3100aff9ba70de8fcf

・libMTVMFCls.so		md5sum: 0c0fa1ebff423529117f454c2b36d736

※上記のMD5ハッシュと異なるものでは使用できない可能性があります。

※これらのライブラリをAndroid 4.4(KitKat)で動作させるためには次の置換を行う必要があります。

`_ZN7android10VectorImpl19reservedVectorImpl?Ev` (?は数字)

↓

`_ZNK7android10VectorImpl8itemSizeEv`

`mNativeSurface`

↓
`mNativeObject`

(文字列の最後にNULL文字(0x00)を入れることを忘れずに)


#ビルド方法
1. AOSPのソースコードをビルドする
2. Fake libsurfaceflinger_clientのソースディレクトリに移動しmmコマンドを実行する


#使用方法
ライブラリを/system/libにコピーする


#その他
このソフトウェアはAOSPのソースコードを流用しています。ありがとうございました。

このソフトウェアはGeneral Public License version 3でライセンスされています。
詳細はLICENSEをご覧ください。
再配布等を行う場合はライセンスに従ってください。

NMIはNewport Media Inc.の略称です。
