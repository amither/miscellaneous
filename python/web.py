import urllib2
import json
import sys
import time

d_f_id = {
	'j1702':5056606,
	'j1502':5056604,
    'j1102':5056600,
    
}

def click(fname):
    fid = d_f_id[fname]
    request = urllib2.Request("https://mfang.vanke.com/m1/ActivityTarget/AddPrice")
    request.add_header("Referer", "https://mfang.vanke.com/m1/ActivityTarget/Auction?id={}".format(fid))
    request.add_header("content-type", "application/x-www-form-urlencoded")
    request.add_header("Cookie", ".AspNetCore.Antiforgery.pneJtbUogwA=CfDJ8KD4htk6mc5Htzt1sfpYBEVRapYG5qetrR-pxrVQfW5JzaKT0pXFBjoATJyWABfZldyU6GBJedLiNHokrf_yqqiWFIp3MXngRz496KEu4VTeicMcQm9rbeESf88_CZLYM9112Y1OC6Z_E-_wc3vE-qQ; vkefang=CfDJ8KD4htk6mc5Htzt1sfpYBEXivFTOeU4W33KAwnyA09YLMsSDmkRKTt_UHlKqz0IU8lxOXduBcXDuNOJS9ott5U8X2QDLnvWGTMv_U3ID47bGjXVLeRaJlLpuaprXr7Ie6Noy4s4jSsHLOenj2YfOowLRG2zzvoazRASEyDR5mq2u09Cq0Uk4zvXcsUTiwN4x4P6EGBk9l4oquZqAWntT7QMKBW7oWF1a5rIlLbYaTNIqomRyvtD8lmNRVqWgCqmrXvrxRymeGg1EA856fzZjiYSnQWG1GkXHgVGtsHXRju03-es0ImTynWQGLPixm3Pa7XCorOOGQKBzmjKh8m2lcqZDpzHMeY1jCPnooAIUBH_FtlwKRKfrFw7oHd9mvauNkRh_ZpFSPnvHDGlM4nn9nkoSzVMvQgIH0GKlUOjLEvrC_Nmeg4dNMw_Qa4_NtD77QmNv4HI2Hk-n70LXKCSnFGFR7EdudNyU7IK8LmY6-bZ97cLW8ezfGCPswTiGK60I3usWeX7k_a5NyjiIUIkEc_POAdIShlqwzvNRUFnv4A7E2Kad_j7acgCXEXcT6F8XNKH9fIanyNGL3GO9f_cx87dCmsIfARJp8zxsoBG7MZBVmoJFt9Idz9zZR0_mt7m62eQSBRaz6xCQ4bJoCIN6l4s44Jv_jt2sOaE716nN3-NxvSMtFO7397lDnwM5bPo24g; vanke.efang168_uprice=23; sitename_vanke.efang168_uprice=%25e6%25b7%25b1%25e5%259c%25b3; remind21731=21731; efanglad=2018%2F11%2F27%2018%3A51%3A07; Hm_lvt_7f8a3fed4e5181142e4c1f289ba3dd80=1543315000; Hm_lpvt_7f8a3fed4e5181142e4c1f289ba3dd80=1543315884; fang_vanke_yevs=1")
    request.add_header("User-Agent", "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.87 Safari/537.36")
    request.add_header("x-requested-with","XMLHttpRequest")
    request.add_data("id={}&site=23&price=4370000.00+&openType=0&__RequestVerificationToken=CfDJ8KD4htk6mc5Htzt1sfpYBEXmuJkpBivekNRBjbJQrROehnwiLPhOYpHEzwQ80NM6d_R_tBLw8WusGD4V_Z_tx0DkRIMKVvONqMtOEFT7bueJ-PyDxaZFhidJHm1Yv-Y49YeInH92SSYEMLWW2ToK4s-Ei-GI-caRSg6KiUyGg5z04n2Eqxpj7COJvj01vfPy2g".format(fid))
    f = urllib2.urlopen(request)
    data = f.read()
    print(data)
    f.close()
    jdata = json.loads(data)
    if jdata['Success'] == True:
        sys.exit(0)
	
	
if __name__ == '__main__':
    click('j1702')
    click('j1502')
    time.sleep(5)