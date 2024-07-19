#############################################################################
# Copyright 1996-2016 Synopsys, Inc.                                        #
#                                                                           #
# This Synopsys software and all associated documentation are proprietary   #
# to Synopsys, Inc. and may only be used pursuant to the terms and          #
# conditions of a written license agreement with Synopsys, Inc.             #
# All other use, reproduction, modification, or distribution of the         #
# Synopsys software or the associated documentation is strictly prohibited. #
#############################################################################

import os
import sys
import shutil
import imp
import time

vdk_name = os.environ['TEST_VDK_NAME']
vdk_template = os.environ['TEST_VDK_TEMPLATE']
vdk_version  = os.environ['TEST_VDK_VERSION']
vpconfig = os.environ['TEST_VPCONFIG']
output = os.environ['DATA_OUTPUT_FOLDER']

vpconfig_name = os.path.basename(vpconfig).replace('.vpcfg', '')

print "vpconfig_name is " + vpconfig_name
print "vpconfig is " + vpconfig
print "vdk_name is " + vdk_name
#############################################################################
# Import script for fix
#############################################################################
fix_path=os.environ['TEST_VPCONFIG']
fix_path=fix_path[:(fix_path.index('VDK')+3)]+'\\patches\\'
fix=imp.load_source("fix",fix_path+"fix.py")

#############################################################################
# Setup VDK
#############################################################################
if (vdk_name not in vdkcreator.get_projects()):
    # empty workspace
    vdk = vdkcreator.create_fixed_vdk(vdk_name, force=True, template=vdkcreator.get_template(vdk_template, vdk_version))
else:
    vdk = vdkcreator.load(vdk_name)

#############################################################################
# load, configure & store VPConfig
#############################################################################

if (vpconfig_name not in vdk.get_vp_configs()):
    vdk.import_external_vp_config(vpconfig)

vpconfig = vdk.get_vp_config(vpconfig_name)

#paramater_overrides = [
# ('ECU.MCU.Base.Peripherals.HSE.M7', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_HSE_CM7.axf'),
# ('ECU.MCU.LLCE.CM0PLUS_0', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM0PLUS_0.axf'),
# ('ECU.MCU.LLCE.CM0PLUS_1', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM0PLUS_1.axf'),
# ('ECU.MCU.LLCE.CM0PLUS_2', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM0PLUS_2.axf'),
# ('ECU.MCU.LLCE.CM0PLUS_3', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM0PLUS_3.axf'),
# ('ECU.MCU.Base.Cores.CM7_0', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM7_0.axf'),
# ('ECU.MCU.Base.Cores.CM7_1', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM7_1.axf'),
# ('ECU.MCU.Base.Cores.CM7_2', 'EXTRA_PROPERTIES', '/ImageInfo/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_CM7_2.axf'),
# ('ECU.MCU.Base.Cores.CPU_clusters.A53_0', 'EXTRA_PROPERTIES', '/ImageInfo/cpu0/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/image_A53.axf'),
# ('ECU.MCU.Base.Cores.CPU_clusters.A53_0', 'EXTRA_PROPERTIES', '/ImageInfo/cpu1/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/dummy_binary/dummy_a53_wfi_bin.axf'),
# ('ECU.MCU.Base.Cores.CPU_clusters.A53_1', 'EXTRA_PROPERTIES', '/ImageInfo/cpu0/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/dummy_binary/dummy_a53_wfi_bin.axf'),
# ('ECU.MCU.Base.Cores.CPU_clusters.A53_1', 'EXTRA_PROPERTIES', '/ImageInfo/cpu1/initial_image', '../../../../../../../../../../../../vnv_dist/beart/beart/vpconfigs/S32G/dummy_binary/dummy_a53_wfi_bin.axf')
#]

#for (module, property, parameter, value) in paramater_overrides:
#    vpconfig.set_parameter_value_override(module, property, parameter, value)

#new_vpconfig_name = 'mod_%s' % (vpconfig_name)
#vpconfig_path = os.path.join(os.path.dirname(vpconfig.get_path()),'..', new_vpconfig_name)
#vpconfig.save_as(vpconfig_path, new_vpconfig_name, True)

#Copying fix libraries
fix.Apply_Fix()

vpconfig.save()

max_errors = 2
for run in range(max_errors):
    try:
        print "Trying to connect vpexplorer"
        vpconfig.run()
        break
    except:
        print "fail, retry one time"
        time.sleep(1)
        pass
