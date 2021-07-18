# snake
貪食蛇遊戲snake game 

使用C/C++製作

環境:C++11

程式遊玩的畫面

![snake1](https://user-images.githubusercontent.com/87599252/126061890-422cb203-a891-4e8f-b575-3c0821b0eacd.png)


結束時的畫面

![snake2](https://user-images.githubusercontent.com/87599252/126061895-59206072-5165-4075-8a4e-26d609d9ee1a.png)


程式改良多次，從原本每一次蛇的移動都cls刷新畫面，會導致使用者遊玩時，視覺上體驗不佳

後來改成只更新蛇的本體印在畫面上的部分，和座標位置更新
