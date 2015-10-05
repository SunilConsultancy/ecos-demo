ECOS_REPOSITORY=/opt/ecos/packages && export ECOS_REPOSITORY
cd /home/ecostest/kernel-net
ecosconfig new linux
ecosconfig add fileio net freebst_net eth_drivers
ecosconfig tree

