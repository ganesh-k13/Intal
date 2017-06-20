import subprocess
from random import randint

testcases = 20

#ADDITION
for _ in range(testcases):
	num1 = randint(-100000000000000000000, 100000000000000000000)
	num2 = randint(-100000000000000000000, 100000000000000000000)

	p = subprocess.Popen(['./test', '-a'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out, err = p.communicate(str(num1)+" "+str(num2))
	
	at_res = num1 + num2
	ob_res = out.split()[0]
	
	if(int(ob_res) == at_res):
		print "%-30s" % ("ADDITION Test case " + str(_ + 1) + ":") + " Passed" 
	else:
		print "Failed at testcase: " + str( _ + 1) + " For i/p: " + str(num1) + " + " + str(num2)
		print "Obtained output: " + ob_res + " " + "Actual output: " + str(at_res)
		exit(0)
		
print("\n")
#SUBTRACTION
for _ in range(testcases):
	num1 = randint(-100000000000000000000, 100000000000000000000)
	num2 = randint(-100000000000000000000, 100000000000000000000)

	p = subprocess.Popen(['./test', '-s'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out, err = p.communicate(str(num1)+" "+str(num2))
	
	at_res = num1 - num2
	ob_res = out.split()[0]
	
	if(int(ob_res) == at_res):
		print "%-30s" % ("SUBTRACTION Test case " + str(_ + 1) + ":") + " Passed" 
	else:
		print "Failed at testcase: " + str( _ + 1) + " For i/p: " + str(num1) + " - " + str(num2)
		print "Obtained output: " + ob_res + " " + "Actual output: " + str(at_res)
		exit(0)

print("\n")		
#MULTIPLICATION
for _ in range(testcases):
	num1 = randint(-100000000000000000000, 100000000000000000000)
	num2 = randint(-100000000000000000000, 100000000000000000000)

	p = subprocess.Popen(['./test', '-m'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out, err = p.communicate(str(num1)+" "+str(num2))
	
	at_res = num1 * num2
	ob_res = out.split()[0]
	
	if(int(ob_res) == at_res):
		print "%-30s" % ("MULTIPLICATION Test case " + str(_ + 1) + ":") + " Passed" 
	else:
		print "Failed at testcase: " + str( _ + 1) + " For i/p: " + str(num1) + " * " + str(num2)
		print "Obtained output: " + ob_res + " " + "Actual output: " + str(at_res)
		exit(0)

print("\n")
#DIVIVSION
for _ in range(testcases):
	num1 = randint(100000000000000000000, 1000000000000000000000)
	num2 = randint(100000000000000000000, 1000000000000000000000)
	
	p = subprocess.Popen(['./test', '-d'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out, err = p.communicate(str(num1)+" "+str(num2))
	
	at_res = num1 // num2
	ob_res = out.split()[0]
	
	if(int(ob_res) == at_res):
		print "%-30s" % ("DIVISION Test case " + str(_ + 1) + ":") + " Passed" 
	else:
		print "Failed at testcase: " + str( _ + 1) + " For i/p: " + str(num1) + " // " + str(num2)
		print "Obtained output: " + ob_res + " " + "Actual output: " + str(at_res)
		exit(0)
		
print("\n")
#EXPO
for _ in range(testcases):
	num1 = randint(10000000000000, 100000000000000)
	num2 = randint(1, 200)

	p = subprocess.Popen(['./test', '-e'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out, err = p.communicate(str(num1)+" "+str(num2))
	
	at_res = num1 ** num2
	ob_res = out.split()[0]
	
	if(int(ob_res) == at_res):
		print "%-30s" % ("EXPONENTIATION Test case " + str(_ + 1) + ":") + " Passed" 
	else:
		print "Failed at testcase: " + str( _ + 1) + " For i/p: " + str(num1) + " ^ " + str(num2)
		print "Obtained output: " + ob_res + " " + "Actual output: " + str(at_res)
		exit(0)
		
print "\n\nALL TESTCASES HAVE PASSED!!!\n\n"