#!/bin/sh

OPT='-Nslf'

#
# driver patches - mostly to improve usability
#

patch $OPT ../media_tree/drivers/media/dvb/dvb-core/dvb_frontend.c dvb_frontend.c.diff
patch $OPT -R ../media_tree/drivers/media/video/uvc/uvc_video.c uvc_video.c.diff
patch $OPT -R ../media_tree/drivers/media/video/uvc/uvcvideo.h uvcvideo.h.diff
patch $OPT -R ../media_tree/drivers/media/video/v4l2-dev.c v4l2-dev.c.diff
patch $OPT ../media_tree/drivers/media/video/videobuf2-core.c videobuf2-core.c.diff
patch $OPT ../media_tree/drivers/media/video/videobuf2-memops.c videobuf2-memops.c.diff
patch $OPT ../media_tree/drivers/media/video/videobuf2-vmalloc.c videobuf2-vmalloc.c.diff
patch $OPT -R ../media_tree/include/linux/dvb/frontend.h frontend.h.diff
patch $OPT -R ../media_tree/include/linux/input.h input.h.diff
patch $OPT ../media_tree/drivers/staging/media/as102/as102_drv.h as102_drv.h.diff
patch $OPT ../media_tree/drivers/media/dvb/dvb-usb/usb-urb.c usb-urb.c.diff
patch $OPT ../media_tree/drivers/media/video/gspca/gspca.c gspca.diff 
patch $OPT ../media_tree/drivers/media/video/stk-webcam.h stk-webcam.h.diff
patch $OPT ../media_tree/include/sound/ac97_codec.h ac97_codec.h.diff
patch $OPT ../media_tree/include/linux/dvb/ca.h ca.h.diff

sed -e "s/dbg[(]/dib_&/g" -i .orig ../media_tree/drivers/media/common/tuners/tda18212.c
sed -e "s/err[(]/cx_&/g" -e "s/info[(]/cx_&/g" -i .orig ../media_tree/drivers/media/dvb/frontends/cx24123.c
sed -e "s/err[(]/dib_&/g" -e "s/info[(]/dib_&/g" -e "s/deb_dib_/deb_/g" -i .orig ../media_tree/drivers/media/dvb/frontends/dib3000mb.c
sed -e "s/err[(]/dib_&/g" -e "s/info[(]/dib_&/g" -e "s/warn[(]/dib_&/g" -e "s/deb_dib_/deb_/g" -i .orig ../media_tree/drivers/media/dvb/frontends/dib3000mb_priv.h
sed -e "s/sleep[(,]/do_&/g" -e "s/mdo_sleep/msleep/g" -i .orig ../media_tree/drivers/media/dvb/frontends/tda18271c2dd.c
sed -e "s/info[(]/itx_&/g" -e "s/itx_itx_/itx_/g" -i .orig ../media_tree/drivers/media/dvb/frontends/it913x-fe.c
sed -e "s/info[(]/m88_&/g" -e "s/m88_m88_/m88_/g" -i .orig ../media_tree/drivers/media/dvb/frontends/m88rs2000.c

exit 0
