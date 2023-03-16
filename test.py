import sys
import zipfile
import os
import time

def zip_extractall(zip_file_path, extractpath):
    all_file = []

    # 注意压缩格式选择
    frzip = zipfile.ZipFile(zip_file_path, 'r', zipfile.ZIP_DEFLATED)
    # 获取解压后根目录
    app_root_dir = frzip.namelist()[0][:-1]
    # 保留原修改时间
    for file in frzip.infolist():
    	# 先获取原文件的时间
        d = file.date_time
        gettime = "%s/%s/%s %s:%s" % (d[0], d[1], d[2], d[3], d[4])
        # 先解压文件
        frzip.extract(file, extractpath)
        # 获取解压后文件的绝对路径
        filep = os.path.join(extractpath, file.filename)
        all_file.append(filep)
        timearry = time.mktime(time.strptime(gettime, '%Y/%m/%d %H:%M'))
        # 设置解压后的修改时间(这里把修改时间与访问时间设为一样了,windows系统)
        os.utime(filep, (timearry, timearry))
    print(all_file[-1])   
    frzip.close()
    
if __name__ == '__main__':
    zip_extractall('IPPVideo.zip', "./testss")
    pass
