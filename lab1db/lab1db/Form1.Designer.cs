namespace lab1db
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.GridChild = new System.Windows.Forms.DataGridView();
            this.GridParent = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.GridChild)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridParent)).BeginInit();
            this.SuspendLayout();
            // 
            // GridChild
            // 
            this.GridChild.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.GridChild.Location = new System.Drawing.Point(627, 36);
            this.GridChild.Name = "GridChild";
            this.GridChild.RowTemplate.Height = 24;
            this.GridChild.Size = new System.Drawing.Size(465, 271);
            this.GridChild.TabIndex = 0;
            this.GridChild.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.GridChild_CellContentClick);
            // 
            // GridParent
            // 
            this.GridParent.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.GridParent.Location = new System.Drawing.Point(39, 36);
            this.GridParent.Name = "GridParent";
            this.GridParent.RowTemplate.Height = 24;
            this.GridParent.Size = new System.Drawing.Size(473, 271);
            this.GridParent.TabIndex = 1;
            this.GridParent.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.GridParent_CellContentClick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(794, 386);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(161, 61);
            this.button1.TabIndex = 2;
            this.button1.Text = "Update";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(198, 386);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(150, 61);
            this.button2.TabIndex = 3;
            this.button2.Text = "Connect";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1168, 546);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.GridParent);
            this.Controls.Add(this.GridChild);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.GridChild)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.GridParent)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        
        private System.Windows.Forms.DataGridView GridChild;
        private System.Windows.Forms.DataGridView GridParent;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}

