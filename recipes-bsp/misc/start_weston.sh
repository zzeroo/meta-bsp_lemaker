mkdir -p /tmp/$USER-weston && chmod 0700 /tmp/$USER-weston && export XDG_RUNTIME_DIR=/tmp/$USER-weston
weston --tty=1 --backend=fbdev-backend.so
