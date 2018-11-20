package me.aflak.libraries.ui.chat.presenter;

import android.app.Activity;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.Handler;


import me.aflak.bluetooth.BluetoothCallback;
import me.aflak.bluetooth.DeviceCallback;
import me.aflak.libraries.R;
import me.aflak.libraries.ui.chat.interactor.ChatInteractor;
import me.aflak.libraries.ui.chat.view.ChatView;

/**
 * Created by Omar on 20/12/2017.
 */

public class ChatPresenterImpl implements ChatPresenter {
    private ChatView view;
    private ChatInteractor interactor;
    private BluetoothDevice device;

    public ChatPresenterImpl(ChatView view, ChatInteractor interactor) {
        this.view = view;
        this.interactor = interactor;
    }

    @Override
    public void onCreate(Intent intent) {
        if(intent.getExtras()!=null) {
            device = intent.getExtras().getParcelable("device");
            view.enableHWButton(false);
        }
    }

    @Override
    public void onHelloWorld() {
        interactor.sendMessage("Hello World !");
    }

    @Override
    public void onForward() {
        interactor.sendMessage("w");
    }

    @Override
    public void onBack() {
        interactor.sendMessage("s");
    }

    @Override
    public void onLeft() {
        interactor.sendMessage("a");
    }

    @Override
    public void onRight() {
        interactor.sendMessage("d");
    }

    @Override
    public void onLevel1() {
        interactor.sendMessage("0");
    }

    @Override
    public void onLevel2() {
        interactor.sendMessage("1");
    }

    @Override
    public void onLevel3() {
        interactor.sendMessage("2");
    }

    @Override
    public void onLevel4() {
        interactor.sendMessage("3");
    }

    @Override
    public void onLevel5() {
        interactor.sendMessage("4");
    }

    @Override
    public void onLevel6() {
        interactor.sendMessage("5");
    }

    private DeviceCallback communicationCallback = new DeviceCallback() {
        @Override
        public void onDeviceConnected(BluetoothDevice device) {
            view.setStatus(R.string.bluetooth_connected);
            view.enableHWButton(true);
        }

        @Override
        public void onDeviceDisconnected(BluetoothDevice device, String message) {
            view.setStatus(R.string.bluetooth_connecting);
            view.enableHWButton(false);
            interactor.connectToDevice(device, communicationCallback);
        }

        @Override
        public void onMessage(String message) {
        }

        @Override
        public void onError(String message) {
            view.setStatus(message);
        }

        @Override
        public void onConnectError(final BluetoothDevice device, String message) {
            view.setStatus(R.string.bluetooth_connect_in_3sec);
            view.showToast("New attempt in 3 sec...");
            new Handler().postDelayed(new Runnable() {
                @Override
                public void run() {
                    interactor.connectToDevice(device, communicationCallback);
                }
            }, 3000);
        }
    };

    @Override
    public void onStart(Activity activity) {
        interactor.onStart(bluetoothCallback, activity);
        if(interactor.isBluetoothEnabled()){
            interactor.connectToDevice(device, communicationCallback);
            view.setStatus(R.string.bluetooth_connecting);
        }
        else{
            interactor.enableBluetooth();
        }
    }

    @Override
    public void onStop() {
        interactor.onStop();
    }

    private BluetoothCallback bluetoothCallback = new BluetoothCallback() {
        @Override
        public void onBluetoothTurningOn() {

        }

        @Override
        public void onBluetoothOn() {
            interactor.connectToDevice(device, communicationCallback);
            view.setStatus(R.string.bluetooth_connecting);
            view.enableHWButton(false);
        }

        @Override
        public void onBluetoothTurningOff() {

        }

        @Override
        public void onBluetoothOff() {

        }

        @Override
        public void onUserDeniedActivation() {

        }
    };
}
