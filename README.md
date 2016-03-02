# MJOY16-CN
因需DIY四轴地面站摇杆，接触了MJOY16
MJOY16由Mindaugas Milasauskas开发，硬件开源，软件不开源，至今还很有研究价值。作者开发了MJOY（开源，以mega8为主控），以及这个以Mega16为主控的MJOY16，设计得很规范，支持8线性轴输入和64个按键，16个拨动开关，4个苦力帽。很适合DIY
现在作者已经找不到踪迹了，俄罗斯人在此基础上开发了MMJOY并借助arduino开源。arduino虽然简单易用，但主控是mega32，不适合手工DIY，还是想用原生的C代码来改进MJOY16，因此做了个开发板MJOY16-CN，支持原版固件，打算业余时间搞清楚源码来开源，供广大魔友研究。基本保留了原作者的原版电路，以及使用40pin IDE接口扩展输入端子的想法。 将mega16的4组IO引脚全部引出，增加JTAG调试接口，应该来说可用性很强了，完全可以作为avr的开发板来做其他用途。
成品硬件请访问： https://tb123kuai.taobao.com
开发教程：http://www.123kuai.com/index.php?m=content&c=index&a=lists&catid=32
