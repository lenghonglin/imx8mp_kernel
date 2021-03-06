/****************************************************************************
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 VeriSilicon Holdings Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************
 *
 * The GPL License (GPL)
 *
 * Copyright (c) 2020 VeriSilicon Holdings Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;
 *
 *****************************************************************************
 *
 * Note: This software is released under dual MIT and GPL licenses. A
 * recipient may use this file under the terms of either the MIT license or
 * GPL License. If you wish to use only one license not the other, you can
 * indicate your decision by deleting one of the above license notices in your
 * version of this file.
 *
 *****************************************************************************/
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/i2c.h>
#include "csi_ioctl.h"
#include "vivcsi_hub.h"

unsigned int vvcsi_register_hardware(struct vvcam_csi_dev *dev, struct vvcam_csi_hardware_function_s *func)
{
	int ret = 0;
	if (func == NULL)
	{
		return -1;
	}

	memcpy(&dev->csi_hard_func,func,sizeof(struct vvcam_csi_hardware_function_s));
	return 0;
}

int vivcsi_hub_init(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.init == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.init(dev);

	return ret;
}


int vivcsi_hub_reset(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.reset == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.reset(dev);

	return ret;
}


int vivcsi_hub_set_power(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.set_power == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.set_power(dev);

	return ret;
}

int vivcsi_hub_get_power(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.get_power == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.get_power(dev);

	return ret;
}

int vivcsi_hub_set_clock(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.set_clock == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.set_clock(dev);

	return ret;
}

int vivcsi_hub_get_clock(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.get_clock == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.get_clock(dev);

	return ret;
}


int vivcsi_hub_set_stream_control(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.set_stream_control == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.set_stream_control(dev);

	return ret;
}

int vivcsi_hub_get_stream_control(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.get_stream_control == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.get_stream_control(dev);

	return ret;
}

int vivcsi_hub_set_fmt(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.set_fmt == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.set_fmt(dev);

	return ret;
}

int vivcsi_hub_get_fmt(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.get_fmt == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.get_fmt(dev);

	return ret;
}

int vivcsi_hub_set_vc_select(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.set_vc_select == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.set_vc_select(dev);

	return ret;
}


int vivcsi_hub_get_vc_select(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.get_vc_select == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.get_vc_select(dev);

	return ret;
}

int vivcsi_hub_set_csi_lane_cfg(struct vvcam_csi_dev *dev)
{
	int ret = 0;
	if(NULL == dev)
	{
		pr_err("%s:dev is null!\n", __func__);
		return -1;
	}

	if (dev->csi_hard_func.set_lane_cfg == NULL)
	{
		pr_err("%s:csi_hard_func is NULL!\n", __func__);
		return -1;
	}

	ret = dev->csi_hard_func.set_lane_cfg(dev);

	return ret;

}

