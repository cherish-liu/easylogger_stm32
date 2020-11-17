本工程是 easylogger 移植到 stm32 工程


elog_port.c：elog移植接口文件； 
elog.c：elog核心功能源码； 
elog_utils.c：elog所用到的一些c库工具函数实现； 
elog_buf.c（可选添加）：elog缓冲输出模式源码； 
elog_async.c（任选添加）：elog异步输出模式源码；


elog_cfg.h 定义了输出日志的级别

