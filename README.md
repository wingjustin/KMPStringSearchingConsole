# KMPStringSearchingConsole

<h3>KMP Algorithm</h3>

<p>
首先讓模式串跟自己做配對進行預處理, 求的是最長的相同前後綴長度,得出next array, 其用處為在配對到後綴失敗時模式串跳去前面有相同前綴位置的下一個字符再配對,省去重新檢查已配對過的相同前綴。
</p>
