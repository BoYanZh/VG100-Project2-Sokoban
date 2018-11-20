package me.aflak.libraries.ui.chat.presenter;

import android.app.Activity;
import android.content.Intent;

/**
 * Created by Omar on 20/12/2017.
 */

public interface ChatPresenter {
    void onCreate(Intent intent);
    void onHelloWorld();
    void onForward();
    void onBack();
    void onLeft();
    void onRight();
    void onLevel1();
    void onLevel2();
    void onLevel3();
    void onLevel4();
    void onLevel5();
    void onLevel6();
    void onStart(Activity activity);
    void onStop();
}
