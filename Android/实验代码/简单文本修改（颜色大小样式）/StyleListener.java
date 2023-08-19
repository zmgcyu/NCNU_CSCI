package com.example.myapplication;

import android.graphics.Typeface;
import android.view.View;
import android.widget.TextView;

public class StyleListener implements View.OnClickListener{
    TextView testText;
    int flag = 0;
    //用0来表示默认字体；1来表示斜体；2表示粗体；3表示粗斜体
    public StyleListener(TextView tv){
        testText = tv;
    }
    @Override
    public void onClick(View view) {
        Typeface tf = testText.getTypeface();//获取当前文本框字体的样式
        switch (view.getId()){
            case R.id.btnBold:
                if(flag==1||flag==3){
                    testText.setTypeface(Typeface.MONOSPACE, Typeface.BOLD_ITALIC);//将文本框字体设为粗斜体
                    flag = 3;
                }
                else {
                    testText.setTypeface(Typeface.MONOSPACE,Typeface.BOLD);//将文本框字体设为粗体
                    flag = 2;
                }
                break;
            case R.id.btnTilter:
                if(flag==2||flag==3){
                    testText.setTypeface(Typeface.MONOSPACE, Typeface.BOLD_ITALIC);
                    flag = 3;
                }
                else{
                    testText.setTypeface(Typeface.MONOSPACE,Typeface.ITALIC);//将文本框字体设为斜体
                    flag = 1;
                }
                break;
            case R.id.btnDefault2:
                testText.setTypeface(Typeface.MONOSPACE,Typeface.NORMAL);//将文本框字体设为默认
                flag = 0;
                break;
        }
    }
}
