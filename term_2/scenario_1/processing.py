import openpyxl, pprint

print('Opening workbook...') 
   
wb = openpyxl.load_workbook('CopperWireData.xlsx', data_only = True)

sheet = wb.get_sheet_by_name('Wire Data')

wireData = {}

for row in range(3, sheet.max_row + 1):
	gauge = sheet['A' + str(row)].value
	copper = sheet['B' + str(row)].value
	wire = sheet['C' + str(row)].value
	
	# wire = round(wire,3)
	
	wireData[gauge] = {'spec': {'copper': copper, 'full': wire}}
	
print('Writing results...')
resultFile = open('output.py', 'w')
resultFile.write('allData = ' + pprint.pformat(wireData))
resultFile.close()
print('Done.')	