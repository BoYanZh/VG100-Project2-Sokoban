package me.aflak.libraries.ui.chat.view;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import javax.inject.Inject;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;
import me.aflak.libraries.MyApp;
import me.aflak.libraries.R;
import me.aflak.libraries.data.BluetoothModule;
import me.aflak.libraries.ui.chat.data.ChatModule;
import me.aflak.libraries.ui.chat.data.DaggerChatComponent;
import me.aflak.libraries.ui.chat.presenter.ChatPresenter;

/**
 * Created by Omar on 20/12/2017.
 */
public class ChatActivity extends AppCompatActivity implements ChatView{
    @BindView(R.id.activity_chat_status) TextView state;
    @BindView(R.id.forward_button) Button forward;
    @BindView(R.id.back_button) Button back;
    @BindView(R.id.left_button) Button left;
    @BindView(R.id.right_button) Button right;
    @BindView(R.id.level1_button) Button level1;
    @BindView(R.id.level2_button) Button level2;
    @BindView(R.id.level3_button) Button level3;
    @BindView(R.id.level4_button) Button level4;
    @BindView(R.id.level5_button) Button level5;
    @BindView(R.id.level6_button) Button level6;

    @Inject ChatPresenter presenter;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_chat);

        DaggerChatComponent.builder()
            .bluetoothModule(MyApp.app().bluetoothModule())
            .chatModule(new ChatModule(this))
            .build().inject(this);

        ButterKnife.bind(this);

        presenter.onCreate(getIntent());
    }

    @OnClick(R.id.forward_button)
    public void onForward(){
        presenter.onForward();
    }

    @OnClick(R.id.back_button)
    public void onBack(){
        presenter.onBack();
    }

    @OnClick(R.id.left_button)
    public void onLeft(){
        presenter.onLeft();
    }

    @OnClick(R.id.right_button)
    public void onRight(){
        presenter.onRight();
    }

    @OnClick(R.id.level1_button)
    public void onLevel1(){
        presenter.onLevel1();
    }

    @OnClick(R.id.level2_button)
    public void onLevel2(){
        presenter.onLevel2();
    }

    @OnClick(R.id.level3_button)
    public void onLevel3(){
        presenter.onLevel3();
    }

    @OnClick(R.id.level4_button)
    public void onLevel4(){
        presenter.onLevel4();
    }

    @OnClick(R.id.level5_button)
    public void onLevel5(){
        presenter.onLevel5();
    }

    @OnClick(R.id.level6_button)
    public void onLevel6(){
        presenter.onLevel6();
    }

    @Override
    public void setStatus(String status) {
        state.setText(status);
    }

    @Override
    public void setStatus(int resId) {
        state.setText(resId);
    }

    @Override
    public void enableHWButton(boolean enabled) {
        forward.setEnabled(enabled);
        back.setEnabled(enabled);
        left.setEnabled(enabled);
        right.setEnabled(enabled);
        level1.setEnabled(enabled);
        level2.setEnabled(enabled);
        level3.setEnabled(enabled);
        level4.setEnabled(enabled);
        level5.setEnabled(enabled);
        level6.setEnabled(enabled);
    }

    @Override
    public void showToast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onStart() {
        super.onStart();
        presenter.onStart(this);
    }

    @Override
    protected void onStop() {
        super.onStop();
        presenter.onStop();
    }
}
