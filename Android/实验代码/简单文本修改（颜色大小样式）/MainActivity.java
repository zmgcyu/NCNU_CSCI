package com.example.myapplication;

import android.os.Bundle;
import android.util.TypedValue;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity{
    TextView testText;
    private Button btnRed = null,btnGreen = null,btnBlue = null;
    private Button btnBig = null,btnSmall = null,btnDefault1 = null;
    private Button btnBold = null,btnTilter = null,btnDefault2 = null;
    private EditText edit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    void initView(){
        testText = (TextView)this.findViewById(R.id.testText);

        btnRed = (Button) this.findViewById(R.id.btnRed);
        btnGreen = (Button) this.findViewById(R.id.btnGreen);
        btnBlue = (Button)this.findViewById(R.id.btnBlue);

        btnBig = (Button)this.findViewById(R.id.btnBig);
        btnSmall = (Button)this.findViewById(R.id.btnSmall);
        btnDefault1 = (Button)this.findViewById(R.id.btnDefault1);

        btnBold = (Button)this.findViewById(R.id.btnBold);
        btnTilter = (Button)this.findViewById(R.id.btnTilter);
        btnDefault2 = (Button)this.findViewById(R.id.btnDefault2);

        edit = (EditText)this.findViewById(R.id.edit);

        ColorListener myColorListener = new ColorListener();//创建监视器对象

        btnRed.setOnClickListener(myColorListener);//绑定监视器对象
        btnGreen.setOnClickListener(myColorListener);
        btnBlue.setOnClickListener(myColorListener);

        SizeListener mySizeListener = new SizeListener();
        btnBig.setOnClickListener(mySizeListener);
        btnSmall.setOnClickListener(mySizeListener);
        btnDefault1.setOnClickListener(mySizeListener);

        StyleListener myStyleListener = new StyleListener(testText);
        btnBold.setOnClickListener(myStyleListener);
        btnTilter.setOnClickListener(myStyleListener);
        btnDefault2.setOnClickListener(myStyleListener);

        edit.setOnEditorActionListener(new TextView.OnEditorActionListener() {      //内部匿名类
            @Override
            public boolean onEditorAction(TextView textView, int i, KeyEvent keyEvent) {
                testText.setText(edit.getText().toString());
                edit.setText("");
                return false;
            }
        });

    }
    class ColorListener implements View.OnClickListener {//声明监视器类
        @Override
        public void onClick(View v) {//重写onClick方法
            switch (v.getId()){
                case R.id.btnRed :
                    testText.setTextColor(btnRed.getTextColors());//将文本框内容置为红色
                    break;
                case R.id.btnGreen :
                    testText.setTextColor(btnGreen.getTextColors());//将文本框内容置为绿色
                    break;
                case R.id.btnBlue :
                    testText.setTextColor(btnBlue.getTextColors());//将文本框内容置为蓝色
                    break;
            }
        }
    }
    class SizeListener implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            float size = testText.getTextSize();
            switch (v.getId()){
                case R.id.btnBig:
                    size += 2;
                    break;
                case R.id.btnSmall:
                    size -= 2;
                    break;
                case R.id.btnDefault1:
                    size = 48;
                    break;
            }
            testText.setTextSize(TypedValue.COMPLEX_UNIT_PX,size);
        }
    }

}
