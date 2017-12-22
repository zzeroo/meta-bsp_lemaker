# Simple opkg Packet Manager Integration

```
cd ${BUILD_DIR}/tmp/deploy/ipk
python -m SimpleHTTPServer
```

```
# /etc/opkg/base-feeds.conf
src/gz all http://192.168.89.210:8000/all
src/gz bananapro http://192.168.89.210:8000/bananapro
src/gz cortexa7hf-neon-vfpv4 http://192.168.89.210:8000/armv7ahf-neon-vfpv4
```

Update the package manager, search packages and install them like so

```
# opkg update
# opkg list |grep foo
# opkg install foo
```

## Links

* [Intel white-paper](http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/package-manager-white-paper.pdf)
